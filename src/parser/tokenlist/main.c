/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:45:54 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/26 14:31:45 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*get_node(t_parse_program *p)
{
	t_node	*tokenlist_node;
	t_node	*return_node;
	char	*arg;

	if (consume_token(TOKEN, &arg, p))
		return (NULL);
	tokenlist_node = parse_tokenlist(p);
	return_node = new_node(arg, NODE_ARGUMENT);
	if (!return_node)
		return (NULL);
	attach_node(return_node, NULL, tokenlist_node);
	return (return_node);
}

t_node	*parse_tokenlist(t_parse_program *p)
{
	t_node	*node;

	node = get_node(p);
	if (node)
		return (node);
	return (NULL);
}
