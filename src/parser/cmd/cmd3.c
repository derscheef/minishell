/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:25:01 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/10 15:02:11 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*parse_cmd3(t_parse_program *p)
{
	t_node	*scmd_node;
	char	*arg;
	t_node	*return_node;

	arg = NULL;
	scmd_node = parse_simple_cmd(p);
	if (!scmd_node)
		return (NULL);
	if (consume_token(CHAR_DGREATER, NULL, p))
		return (destroy_node(scmd_node), NULL);
	if (consume_token(TOKEN, &arg, p))
	{
		free(arg);
		return (destroy_node(scmd_node), NULL);
	}
	return_node = new_node(arg, NODE_REDIRECT_OUT_APPEND);
	if (!return_node)
	{
		free(arg);
		return (destroy_node(scmd_node), NULL);
	}
	while (!consume_token(TOKEN, &arg, p))
		attach_to_last_node(scmd_node, new_node(arg, NODE_ARGUMENT), NULL);
	attach_node(return_node, scmd_node, NULL);
	return (return_node);
}
