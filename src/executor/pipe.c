/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:02:28 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/08 18:18:58 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_pipe(int fd[2], int *read_pipe, int *write_pipe)
{
	pipe(fd);
	*read_pipe = fd[0];
	*write_pipe = fd[1];
}

#define BUFF_SIZE 100

void	execute_pipe(t_executor *p)
{
	char	buffer[BUFF_SIZE];
	int		og_fd[2];
	t_node	*node;

	og_fd[0] = dup(STDIN_FILENO);
	og_fd[1] = dup(STDOUT_FILENO);
	node = p->node->right;
	execute_command((t_cmd){p->node->left, p->env, p->env_node, false, true,
		og_fd[0], og_fd[1], NULL, NULL, p->exit_code, false, p->main});
	read(og_fd[0], buffer, BUFF_SIZE);
	printf("buffer: %s\n", buffer);
	ft_putstr_fd(buffer, STDOUT_FILENO);
	execute_command((t_cmd){node->left, p->env, p->env_node, true, true,
		og_fd[0], og_fd[1], NULL, NULL, p->exit_code, false, p->main});
	dup2(og_fd[0], STDIN_FILENO);
	dup2(og_fd[1], STDOUT_FILENO);
	close(og_fd[0]);
	close(og_fd[1]);
}
// void	execute_pipe(t_executor *p)
// {
// 	t_node	*node;
// 	int		fd[2];
// 	int		read_pipe;
// 	int		write_pipe;

// 	init_pipe(fd, &read_pipe, &write_pipe);
// 	execute_command((t_cmd){p->node->left, p->env, p->env_node, false, true,
// 		read_pipe, write_pipe, NULL, NULL, p->exit_code, false, p->main});
// 	node = p->node->right;
// 	while (node && node->type == NODE_PIPE)
// 	{
// 		close(write_pipe);
// 		pipe(fd);
// 		write_pipe = fd[1];
// 		execute_command((t_cmd){node->left, p->env, p->env_node, true, true,
// 			read_pipe, write_pipe, NULL, NULL, p->exit_code, false, p->main});
// 		close(read_pipe);
// 		read_pipe = fd[0];
// 		node = node->right;
// 	}
// 	close(write_pipe);
// 	execute_command((t_cmd){node, p->env, p->env_node, true, false, fd[0], 0,
// 		NULL, NULL, p->exit_code, false, p->main});
// 	close(fd[0]);
// }
