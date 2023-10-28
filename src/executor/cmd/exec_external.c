/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:25:34 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/28 18:08:35 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: pass env to execve
bool	execute_external(t_internal_cmd *p)
{
	pid_t	pid;
	int		stdout_fd;
	int		fd;

	pid = fork();
	if (pid < 0)
		return (perror("fork"), true);
	stdout_fd = dup(STDOUT_FILENO);
	if (p->redirect_in)
	{
		fd = open(p->redirect_in, O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else if (p->redirect_out)
	{
		fd = open(p->redirect_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (p->is_stdin)
		dup2(p->fd_read, STDIN_FILENO);
	if (p->is_stdout)
		dup2(p->fd_write, STDOUT_FILENO);
	if (execve(p->av[0], p->av, NULL) == -1)
	{
		dup2(stdout_fd, STDOUT_FILENO);
		printf("Command not found: %s\n", p->av[0]);
		return (true);
	}
	while (waitpid(pid, NULL, 0) <= 0)
		;
	return (false);
}
