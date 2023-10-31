/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:03:58 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/31 16:24:23 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(t_cmd p)
{
	if (!p.node)
		return ;
	if (p.node->type == NODE_CMDPATH)
		execute_simple_command((t_cmd){p.node, p.env, p.env_node, p.is_stdin,
			p.is_stdout, p.fd_read, p.fd_write, NULL, NULL, p.exit_code,
			false});
	else if (p.node->type == NODE_REDIRECT_IN)
		execute_simple_command((t_cmd){p.node->left, p.env, p.env_node,
			p.is_stdin, p.is_stdout, p.fd_read, p.fd_write, p.node->data, NULL,
			p.exit_code, false});
	else if (p.node->type == NODE_REDIRECT_OUT)
		execute_simple_command((t_cmd){p.node->left, p.env, p.env_node,
			p.is_stdin, p.is_stdout, p.fd_read, p.fd_write, NULL, p.node->data,
			p.exit_code, false});
	else if (p.node->type == NODE_REDIRECT_OUT_APPEND)
		execute_simple_command((t_cmd){p.node->left, p.env, p.env_node,
			p.is_stdin, p.is_stdout, p.fd_read, p.fd_write, NULL, p.node->data,
			p.exit_code, true});
	else if (p.node->type == NODE_REDIRECT_IN_HEREDOC)
		execute_heredoc(&p);
}
