/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:25:01 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/10 17:23:18 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: potentially need to free arg on 3. if. Check back later.
// TODO: attach_to_last_node, new_node needs a malloc check and free on fail.
t_node	*parse_cmd1(t_parse_program *p)
{
	t_node	*scmd_node;
	char	*arg;
	t_node	*return_node;
	bool	is_loop;
	t_node	*temp;

	return_node = NULL;
	arg = NULL;
	scmd_node = parse_simple_cmd(p);
	if (!scmd_node)
		return (NULL);
	is_loop = false;
	while (!consume_token(CHAR_LESSER, NULL, p))
	{
		is_loop = true;
		if (consume_token(TOKEN, &arg, p))
			return (free(arg), destroy_node(scmd_node), NULL);
		temp = new_node(arg, NODE_REDIRECT_IN);
		if (!temp)
			return (free(arg), destroy_node(scmd_node), NULL);
		if (return_node)
			attach_to_last_node(return_node, temp, NULL);
		else
			return_node = temp;
	}
	if (!is_loop)
		return (free(arg), destroy_node(scmd_node), NULL);
	while (!consume_token(TOKEN, &arg, p))
		attach_to_last_node(scmd_node, new_node(arg, NODE_ARGUMENT), NULL);
	attach_to_last_node(return_node, scmd_node, NULL);
	return (return_node);
}
