/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:21:31 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 20:48:49 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*parse_cmd(t_parse_program *p)
{
	t_token	*save;
	t_node	*node;

	save = p->cur_token;
	node = parse_cmd1(p);
	if (node)
		return (node);
	p->cur_token = save;
	node = parse_cmd2(p);
	if (node)
		return (node);
	p->cur_token = save;
	node = parse_cmd3(p);
	if (node)
		return (node);
	p->cur_token = save;
	node = parse_cmd4(p);
	if (node)
		return (node);
	p->cur_token = save;
	node = parse_simple_cmd(p);
	if (node)
		return (node);
	return (NULL);
}
