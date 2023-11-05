/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:00:43 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/04 21:13:46 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*parse_cmd2(t_parse_program *p)
{
	t_node	*scmd_node;
	char	*arg;
	t_node	*return_node;

	arg = NULL;
	scmd_node = parse_simple_cmd(p);
	if (!scmd_node)
		return (NULL);
	if (consume_token(CHAR_GREATER, NULL, p))
		return (destroy_node(scmd_node), NULL);
	if (consume_token(TOKEN, &arg, p))
	{
		free(arg);
		return (destroy_node(scmd_node), NULL);
	}
	return_node = new_node(arg, NODE_REDIRECT_OUT);
	if (!return_node)
		return (destroy_node(scmd_node), NULL);
	attach_node(return_node, scmd_node, NULL);
	return (return_node);
}
