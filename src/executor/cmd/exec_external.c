/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:25:34 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/10 18:30:49 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(t_internal_cmd *p)
{
	char	*path;

	path = get_bin_path(p->env_node, p->av[0]);
	if (!path)
	{
		path = ft_strdup(p->av[0]);
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

bool	execute_external(t_internal_cmd *p)
{
	pid_t	pid;
	int		stdout_fd;
	int		fd;
	char	*path;
	int		status;

	path = get_path(p);
	if (!path)
		return (true);
	set_to_ignore();
	pid = fork();
	if (pid == 0)
	{
		handle_signals();
		stdout_fd = dup(STDOUT_FILENO);
		handle_redirect_in(p, &fd);
		handle_redirect_out(p, &fd);
		handle_stdin_stdout(p);
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
