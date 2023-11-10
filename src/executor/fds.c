/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:28:12 by yscheef           #+#    #+#             */
/*   Updated: 2023/11/10 19:03:54 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_input_fd(t_internal_cmd *p)
{
	int	fd;

	fd = open(p->redirect_in, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	return (fd);
}

int	open_output_fd(t_internal_cmd *p)
{
	int	fd;

	if (p->is_double)
		fd = open(p->redirect_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(p->redirect_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	return (fd);
}

int	handle_fd(t_internal_cmd *p)
{
	int	fd;

	fd = 1;
	// if (p->redirect_in)
	// 	fd = open_input_fd(p);
	if (p->redirect_out)
		fd = open_output_fd(p);
	// if (p->is_stdin)
	// {
	// 	dup2(p->fd_read, STDIN_FILENO);
	// 	fd = p->fd_read;
	// }
	if (p->is_stdout)
	{
		dup2(p->fd_write, STDOUT_FILENO);
		fd = p->fd_write;
	}
	return (fd);
}

void	restore_fds(int original_stdout, int original_stdin)
{
	dup2(original_stdout, STDOUT_FILENO);
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdout);
	close(original_stdin);
}
