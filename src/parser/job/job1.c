/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:16:03 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/26 14:29:59 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*parse_job1(t_parse_program *p)
{
	t_node	*cmd_node;
	t_node	*job_node;
	t_node	*return_node;

	cmd_node = parse_cmd(p);
	if (!cmd_node)
		return (NULL);
	if (consume_token(CHAR_PIPE, NULL, p))
		return (destroy_node(cmd_node), NULL);
	job_node = parse_job(p);
	if (!job_node)
		return (destroy_node(cmd_node), NULL);
	return_node = new_node(NULL, NODE_PIPE);
	attach_node(return_node, cmd_node, job_node);
	return (return_node);
}
