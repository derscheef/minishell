/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:25:34 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/17 00:15:28 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(t_internal_cmd *p)
{
	char	*path;

	path = get_bin_path(p->env_node, p->av[0]);
	if (!path)
	{
		// If file exists then check permission else command not found
		if (p->av[0][0] == '.' || p->av[0][0] == '/')
		{
			if (access(p->av[0], F_OK) == 0)
			{
				if (access(p->av[0], X_OK) != 0)
				{
					*p->exit_code = 126;
					ft_putstr_fd(" Permission denied", STDERR_FILENO);
				}
			}
			else
			{
				*p->exit_code = 127;
				ft_putstr_fd(" No such file or directory", STDERR_FILENO);
			}
			return (NULL);
		}
		*p->exit_code = 127;
		ft_putstr_fd(" command not found", STDERR_FILENO);
		return (NULL);
	}
	return (path);
}

void	handle_redirect_in(t_internal_cmd *p, int *fd)
{
	if (p->redirect_in)
	{
		if (p->is_double)
			*fd = open("/dev/stdin", O_RDONLY);
		else
			*fd = open(p->redirect_in, O_RDONLY);
		dup2(*fd, STDIN_FILENO);
		close(*fd);
	}
}

void	handle_redirect_out(t_internal_cmd *p, int *fd)
{
	if (p->redirect_out)
	{
		if (p->is_double)
			*fd = open(p->redirect_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			*fd = open(p->redirect_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(*fd, STDOUT_FILENO);
		close(*fd);
	}
}

void	handle_stdin_stdout(t_internal_cmd *p)
{
	if (p->is_stdin)
		dup2(p->fd_read, STDIN_FILENO);
	if (p->is_stdout)
		dup2(p->fd_write, STDOUT_FILENO);
}

bool	is_empty(char *str)
{
	if (!str)
		return (true);
	while (*str)
	{
		if (*str != ' ')
			return (false);
		str++;
	}
	return (true);
}

static bool	is_directory(char *command)
{
	struct stat	statbuf;

	if (stat(command, &statbuf) != 0)
		return (0);
	if (S_ISDIR(statbuf.st_mode))
	{
		if (*command == '.')
			command++;
		if (*command == '.')
			command++;
		if (*command == '/')
			return (true);
	}
	return (false);
}

bool	execute_external(t_internal_cmd *p)
{
	pid_t	pid;
	int		stdout_fd;
	int		fd;
	char	*path;
	int		status;

	if (is_empty(p->av[0]))
	{
		*p->exit_code = 0;
		return (false);
	}
	if (is_directory(p->av[0]))
	{
		*p->exit_code = 126;
		ft_putstr_fd(" Is a directory", STDERR_FILENO);
		return (false);
	}
	path = get_path(p);
	if (!path)
		return (true);
	set_to_ignore();
	pid = fork();
	if (pid == 0)
	{
		handle_signals();
		stdout_fd = dup(STDOUT_FILENO);
		handle_stdin_stdout(p);
		handle_redirect_in(p, &fd);
		handle_redirect_out(p, &fd);
		execute_bin(p, path, stdout_fd);
		free(path);
		exit(*p->exit_code);
	}
	free(path);
	if (pid < 0)
		return (perror("fork"), true);
	wait_for_child(p, pid, &status);
	return (false);
}
