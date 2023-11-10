/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:03:58 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/10 19:11:54 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*get_last_redirect(t_node *node)
{
	while (node->left->type == NODE_REDIRECT_IN
		|| node->left->type == NODE_REDIRECT_OUT
		|| node->left->type == NODE_REDIRECT_OUT_APPEND
		|| node->left->type == NODE_REDIRECT_IN_HEREDOC)
	{
		node = node->left;
	}
	return (node);
}

static bool	check_file(t_node *node, int *exit_code)
{
	struct stat	buff;

	if (node->type == NODE_REDIRECT_IN
		|| node->type == NODE_REDIRECT_IN_HEREDOC)
	{
		if (!can_open_file(node->data, R_OK, exit_code))
			return (true);
	}
	else if (node->type == NODE_REDIRECT_OUT
		|| node->type == NODE_REDIRECT_OUT_APPEND)
	{
		if (stat(node->data, &buff) == -1)
			return (false);
		if (access(node->data, W_OK) != 0)
		{
			*exit_code = 1;
			ft_putstr_fd(" Permission denied\n", STDERR_FILENO);
			return (true);
		}
	}
	return (false);
}

static bool	check_files(t_node *node, int *exit_code)
{
	while (node)
	{
		if (check_file(node, exit_code))
			return (true);
		node = node->left;
	}
	return (false);
}

void	execute_command(t_cmd p)
{
	if (!p.node)
		return ;
	if (check_files(p.node, p.exit_code))
		return ;
	if (p.node->type == NODE_CMDPATH)
		execute_simple_command((t_cmd){p.node, p.env, p.env_node, p.is_stdin,
			p.is_stdout, p.fd_read, p.fd_write, NULL, NULL, p.exit_code, false,
			p.main});
	else if (p.node->type == NODE_REDIRECT_IN)
		execute_simple_command((t_cmd){get_last_redirect(p.node)->left, p.env,
			p.env_node, p.is_stdin, p.is_stdout, p.fd_read, p.fd_write,
			get_last_redirect(p.node)->data, NULL, p.exit_code, false, p.main});
	else if (p.node->type == NODE_REDIRECT_OUT)
		execute_simple_command((t_cmd){p.node->left, p.env, p.env_node,
			p.is_stdin, p.is_stdout, p.fd_read, p.fd_write, NULL, p.node->data,
			p.exit_code, false, p.main});
	else if (p.node->type == NODE_REDIRECT_OUT_APPEND)
		execute_simple_command((t_cmd){get_last_redirect(p.node)->left, p.env,
			p.env_node, p.is_stdin, p.is_stdout, p.fd_read, p.fd_write, NULL,
			get_last_redirect(p.node)->data, p.exit_code, true, p.main});
	else if (p.node->type == NODE_REDIRECT_IN_HEREDOC)
		execute_heredoc(&p);
}
