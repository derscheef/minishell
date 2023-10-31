/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:41:00 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/26 14:28:54 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*parse_job(t_parse_program *p)
{
	t_token	*save;
	t_node	*node;

	save = p->cur_token;
	node = parse_job1(p);
	if (node)
		return (node);
	p->cur_token = save;
	node = parse_cmd(p);
	if (node)
		return (node);
	return (NULL);
}
