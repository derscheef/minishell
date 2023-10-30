/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:02:28 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 16:05:53 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// fd[0] = read
// fd[1] = write
void	execute_pipe(t_executor *p)
{
	int		fd[2];
	t_node	*node;
	int		read_pipe;
	int		write_pipe;

	pipe(fd);
	read_pipe = fd[0];
	write_pipe = fd[1];
	execute_command((t_cmd){p->node->right, p->env, p->env_node, false, true, 0,
		write_pipe, NULL, NULL, p->exit_code});
	node = p->node->left;
	while (node && node->type == NODE_PIPE)
	{
		close(write_pipe);
		pipe(fd);
		write_pipe = fd[1];
		execute_command((t_cmd){node->right, p->env, p->env_node, true, true,
			read_pipe, write_pipe, NULL, NULL, p->exit_code});
		close(read_pipe);
		read_pipe = fd[0];
		node = node->left;
	}
	read_pipe = fd[0];
	close(write_pipe);
	execute_command((t_cmd){node, p->env, p->env_node, true, false, read_pipe,
		0, NULL, NULL, p->exit_code});
	close(read_pipe);
}
