/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:01:08 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/03 15:19:44 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_input(char *delim, t_env_node *env, int exit_code)
{
	char	*line;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	line = ft_strdup("");
	while (1)
	{
		tmp = readline("heredoc> ");
		if (!tmp)
			return (line);
		if (!ft_strcmp(tmp, delim))
		{
			free(tmp);
			line = replace_env_var(line, env, exit_code);
			return (line);
		}
		tmp2 = ft_strjoin(tmp, "\n");
		free(tmp);
		tmp3 = line;
		line = ft_strjoin(line, tmp2);
		free(tmp2);
		free(tmp3);
	}
}

int	open_input_fd_heredoc(t_cmd *p)
{
	int	fd;

	fd = open(p->redirect_in, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	return (fd);
}

int	open_output_fd_heredoc(t_cmd *p)
{
	int	fd;

	if (p->is_double)
		fd = open(p->redirect_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(p->redirect_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	return (fd);
}

int	handle_fd_heredoc(t_cmd *p)
{
	int	fd;

	fd = 1;
	if (p->redirect_in)
		fd = open_input_fd_heredoc(p);
	else if (p->redirect_out)
		fd = open_output_fd_heredoc(p);
	if (p->is_stdin)
	{
		dup2(p->fd_read, STDIN_FILENO);
		fd = p->fd_read;
	}
	if (p->is_stdout)
	{
		dup2(p->fd_write, STDOUT_FILENO);
		fd = p->fd_write;
	}
	return (fd);
}

bool	execute_heredoc(t_cmd *p)
{
	char *input;
	int fd[2];
	int original_stdout;
	int original_stdin;

	original_stdout = dup(STDOUT_FILENO);
	original_stdin = dup(STDIN_FILENO);
	if (pipe(fd) == -1)
		return (perror("Error: couldn't create pipe in heredoc"), true);
	input = get_input(p->node->data, p->env_node, *p->exit_code);
	fd[1] = handle_fd_heredoc(p);
	write(fd[1], input, ft_strlen(input));
	free(input);
	close(fd[1]); // Close write end of the pipe
	restore_fds(original_stdout, original_stdin);
	return (false);
}
