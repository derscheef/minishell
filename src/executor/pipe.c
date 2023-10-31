/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:02:28 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/31 17:14:59 by yscheef          ###   ########.fr       */
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

	node = p->node->left;
	init_pipe(fd, &read_pipe, &write_pipe);
	execute_command((t_cmd){p->node->right, p->env, p->env_node, false, true, 0,
		write_pipe, NULL, NULL, p->exit_code, false});
	while (node && node->type == NODE_PIPE)
	{
		close(write_pipe);
		init_pipe(fd, &read_pipe, &write_pipe);
		execute_command((t_cmd){node->right, p->env, p->env_node, true, true,
			read_pipe, write_pipe, NULL, NULL, p->exit_code, false});
		close(read_pipe);
		node = node->left;
	}
	close(write_pipe);
	execute_command((t_cmd){node, p->env, p->env_node, true, false, fd[0], 0,
		NULL, NULL, p->exit_code, false});
	close(fd[0]);
}
