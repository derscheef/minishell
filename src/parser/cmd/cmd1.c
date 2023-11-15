/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:25:01 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/15 02:32:18 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: potentially need to free arg on 3. if. Check back later.
// TODO: attach_to_last_node, new_node needs a malloc check and free on fail.

//   CHAR_LESSER = NODE_REDIRECT_IN,
//  CHAR_GREATER = NODE_REDIRECT_OUT,
//  CHAR_DGREATER = NODE_REDIRECT_OUT_APPEND,
// CHAR_DLESSER = NODE_REDIRECT_IN_HEREDOC

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
	while (true)
	{
		is_loop = true;
		if (!consume_token(CHAR_LESSER, &arg, p))
			temp = new_node(NULL, NODE_REDIRECT_IN);
		else if (!consume_token(CHAR_GREATER, &arg, p))
			temp = new_node(NULL, NODE_REDIRECT_OUT);
		else if (!consume_token(CHAR_DGREATER, &arg, p))
			temp = new_node(NULL, NODE_REDIRECT_OUT_APPEND);
		else if (!consume_token(CHAR_DLESSER, &arg, p))
			temp = new_node(NULL, NODE_REDIRECT_IN_HEREDOC);
		else if (!consume_token(TOKEN, &arg, p))
		{
			attach_to_last_node(scmd_node, new_node(arg, NODE_ARGUMENT), NULL);
			continue ;
		}
		else
			break ;
		if (!temp || consume_token(TOKEN, &arg, p))
			return (free(arg), destroy_node(scmd_node), NULL);
		temp->data = arg;
		if (return_node)
			attach_to_last_node(return_node, temp, NULL);
		else
			return_node = temp;
	}
	if (!is_loop)
		return (free(arg), destroy_node(scmd_node), NULL);
	attach_to_last_node(return_node, scmd_node, NULL);
	return (return_node);
}

// t_node	*parse_cmd1(t_parse_program *p)
// {
// 	t_node	*scmd_node;
// 	char	*arg;
// 	t_node	*return_node;
// 	bool	is_loop;
// 	t_node	*temp;

// 	return_node = NULL;
// 	arg = NULL;
// 	scmd_node = parse_simple_cmd(p);
// 	if (!scmd_node)
// 		return (NULL);
// 	is_loop = false;
// 	while (true)
// 	{
// 		is_loop = true;
// 		if (!consume_token(CHAR_LESSER, &arg, p))
// 			temp = new_node(NULL, NODE_REDIRECT_IN);
// 		else if (!consume_token(CHAR_GREATER, &arg, p))
// 			temp = new_node(NULL, NODE_REDIRECT_OUT);
// 		else if (!consume_token(CHAR_DGREATER, &arg, p))
// 			temp = new_node(NULL, NODE_REDIRECT_OUT_APPEND);
// 		else if (!consume_token(CHAR_DLESSER, &arg, p))
// 			temp = new_node(NULL, NODE_REDIRECT_IN_HEREDOC);
// 		else
// 			break ;
// 		if (!temp || consume_token(TOKEN, &arg, p))
// 			return (free(arg), destroy_node(scmd_node), NULL);
// 		temp->data = arg;
// 		if (return_node)
// 			attach_to_last_node(return_node, temp, NULL);
// 		else
// 			return_node = temp;
// 	}
// 	if (!is_loop)
// 		return (free(arg), destroy_node(scmd_node), NULL);
// 	while (!consume_token(TOKEN, &arg, p))
// 		attach_to_last_node(scmd_node, new_node(arg, NODE_ARGUMENT), NULL);
// 	attach_to_last_node(return_node, scmd_node, NULL);
// 	return (return_node);
// }
