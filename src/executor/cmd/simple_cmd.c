/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:06:16 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 10:58:46 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	init_arguments(t_cmd *p, t_internal_cmd *cmd)
{
	t_node	*node;
	size_t	ac;

	if (!p->node || p->node->type != NODE_CMDPATH)
		return (true);
	node = p->node;
	ac = 0;
	while (node && (node->type == NODE_ARGUMENT || node->type == NODE_CMDPATH))
	{
		ac++;
		node = node->left;
	}
	cmd->ac = ac;
	cmd->av = ft_calloc(ac + 1, sizeof(char *));
	if (!cmd->av)
		return (true);
	cmd->av[ac] = NULL;
	node = p->node;
	ac = 0;
	while (node && (node->type == NODE_ARGUMENT || node->type == NODE_CMDPATH))
	{
		cmd->av[ac] = ft_strdup(node->data);
		ac++;
		node = node->left;
	}
	return (false);
}

static bool	destroy_arguments(t_internal_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (i < cmd->ac)
	{
		free(cmd->av[i]);
		i++;
	}
	free(cmd->av);
	return (false);
}

void	execute_simple_command(t_cmd p)
{
	t_internal_cmd	*cmd;

	cmd = &(t_internal_cmd){0, NULL, p.env, p.env_node, p.is_stdin, p.is_stdout,
		p.fd_read, p.fd_write, p.redirect_in, p.redirect_out};
	if (init_arguments(&p, cmd))
		return ;
	execute_internal_command(cmd);
	destroy_arguments(cmd);
}
