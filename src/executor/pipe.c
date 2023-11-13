/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:02:28 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/12 21:03:38 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_pipe(int fd[2], int *read_pipe, int *write_pipe)
{
	pipe(fd);
	*read_pipe = fd[0];
	*write_pipe = fd[1];
}

void	execute_pipe(t_executor *p)
{
	t_node	*node;
	int		fd[2];
	int		read_pipe;
	int		write_pipe;

	init_pipe(fd, &read_pipe, &write_pipe);
	execute_command((t_cmd){p->node->left, p->env, p->env_node, false, true,
		read_pipe, write_pipe, NULL, NULL, p->exit_code, false, p->main});
	node = p->node->right;
	while (node && node->type == NODE_PIPE)
	{
		close(write_pipe);
		if (pipe(fd) == -1)
			exit(1);
		write_pipe = fd[1];
		execute_command((t_cmd){node->left, p->env, p->env_node, true, true,
			read_pipe, write_pipe, NULL, NULL, p->exit_code, false, p->main});
		close(read_pipe);
		read_pipe = fd[0];
		node = node->right;
	}
	close(write_pipe);
	execute_command((t_cmd){node, p->env, p->env_node, true, false, fd[0], 0,
		NULL, NULL, p->exit_code, false, p->main});
	close(fd[0]);
}
