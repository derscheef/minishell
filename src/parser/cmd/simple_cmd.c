/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:29:09 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/26 14:30:59 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*parse_simple_cmd(t_parse_program *p)
{
	t_node	*tokenlist_node;
	char	*arg;
	t_node	*return_node;

	if (consume_token(TOKEN, &arg, p))
		return (NULL);
	tokenlist_node = parse_tokenlist(p);
	return_node = new_node(arg, NODE_CMDPATH);
	if (!return_node)
		return (NULL);
	attach_node(return_node, NULL, tokenlist_node);
	return (return_node);
}
