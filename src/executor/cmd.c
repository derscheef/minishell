/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:03:58 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/28 16:14:47 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(t_cmd p)
{
	if (!p.node)
		return ;
	if (p.node->type == NODE_CMDPATH)
		execute_simple_command((t_cmd){p.node, p.is_stdin, p.is_stdout,
			p.fd_read, p.fd_write, NULL, NULL});
	else if (p.node->type == NODE_REDIRECT_IN)
		execute_simple_command((t_cmd){p.node->left, p.is_stdin, p.is_stdout,
			p.fd_read, p.fd_write, p.node->data, NULL});
	else if (p.node->type == NODE_REDIRECT_OUT)
		execute_simple_command((t_cmd){p.node->left, p.is_stdin, p.is_stdout,
			p.fd_read, p.fd_write, NULL, p.node->data});
}
