/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:03:58 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/15 21:49:46 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*get_last_redirect(t_node *node)
{
	t_node	*rv;

	if (!node)
		return (NULL);
	rv = NULL;
	if (node->type == NODE_REDIRECT_IN || node->type == NODE_REDIRECT_OUT
		|| node->type == NODE_REDIRECT_OUT_APPEND
		|| node->type == NODE_REDIRECT_IN_HEREDOC)
		rv = node;
	while (node->left && (node->left->type == NODE_REDIRECT_IN
			|| node->left->type == NODE_REDIRECT_OUT
			|| node->left->type == NODE_REDIRECT_OUT_APPEND
			|| node->left->type == NODE_REDIRECT_IN_HEREDOC))
	{
		rv = node->left;
		node = node->left;
	}
	return (rv);
}

static t_node	*get_last_specific_redirect(t_node *node, bool is_in)
{
	t_node	*return_node;

	return_node = NULL;
	while (node)
	{
		if (is_in && (node->type == NODE_REDIRECT_IN
				|| node->type == NODE_REDIRECT_IN_HEREDOC))
			return_node = node;
		else if (!is_in && (node->type == NODE_REDIRECT_OUT
				|| node->type == NODE_REDIRECT_OUT_APPEND))
			return_node = node;
		node = node->left;
	}
	return (return_node);
}

static bool	check_file(t_node *node, int *exit_code)
{
	struct stat	buff;
	int			type;
	int			fd;

	fd = 0;
	if (node->type == NODE_REDIRECT_IN
		|| node->type == NODE_REDIRECT_IN_HEREDOC)
	{
		if (!can_open_file(node->data, R_OK, exit_code))
			return (true);
	}
	else if (node->type == NODE_REDIRECT_OUT
		|| node->type == NODE_REDIRECT_OUT_APPEND)
	{
		if (stat(node->data, &buff) != -1)
		{
			if (access(node->data, W_OK) != 0)
			{
				*exit_code = 1;
				ft_putstr_fd(" Permission denied\n", STDERR_FILENO);
				return (true);
			}
		}
	}
	else
		return (false);
	type = node->type;
	if (type == NODE_REDIRECT_OUT)
		fd = open(node->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == NODE_REDIRECT_OUT_APPEND)
		fd = open(node->data, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (type == NODE_REDIRECT_OUT || type == NODE_REDIRECT_OUT_APPEND)
		close(fd);
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

t_cmd	prepare_command(t_cmd p)
{
	t_cmd	new_cmd;
	t_node	*tmp;

	new_cmd = (t_cmd){p.node, p.env, p.env_node, p.is_stdin, p.is_stdout,
		p.fd_read, p.fd_write, NULL, NULL, p.exit_code, false, p.main};
	tmp = get_last_redirect(p.node);
	if (tmp)
		new_cmd.node = tmp->left;
	tmp = get_last_specific_redirect(p.node, true);
	if (tmp)
	{
		new_cmd.redirect_in = tmp->data;
		if (tmp->type == NODE_REDIRECT_IN_HEREDOC)
			new_cmd.is_double = true;
	}
	tmp = get_last_specific_redirect(p.node, false);
	if (tmp)
	{
		new_cmd.redirect_out = tmp->data;
		if (tmp->type == NODE_REDIRECT_OUT_APPEND)
			new_cmd.is_double = true;
	}
	return (new_cmd);
}

void	execute_command(t_cmd p)
{
	if (!p.node)
		return ;
	if (check_files(p.node, p.exit_code))
		return ;

	if (p.node->type == NODE_CMDPATH || p.node->type == NODE_REDIRECT_IN
		|| p.node->type == NODE_REDIRECT_OUT
		|| p.node->type == NODE_REDIRECT_OUT_APPEND)
	{
		t_cmd new_cmd = prepare_command(p);
		execute_simple_command(new_cmd);
	}
	else if (p.node->type == NODE_REDIRECT_IN_HEREDOC)
	{
		execute_heredoc(&p);
	}
}