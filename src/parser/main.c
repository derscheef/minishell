/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:56:07 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/26 16:05:35 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	init_parse_program(t_parse_program *p, t_main *main)

{
	p->cur_token = main->lexer.tokens;
	p->ast = main->ast;
	return (false);
}

bool	consume_token(t_token_type type, char **strbuffer, t_parse_program *p)
{
	if (!p->cur_token)
		return (true);
	if (p->cur_token->type != type)
	{
		return (true);
	}
	if (strbuffer)
		*strbuffer = ft_strdup(p->cur_token->data);
	p->cur_token = p->cur_token->next;
	return (false);
}

bool	parse(t_main *main)
{
	t_parse_program	p;

	if (init_parse_program(&p, main))
		return (true);
	if (!p.cur_token || !p.ast || main->lexer.ntoks == 0)
		return (true);
	main->ast = parse_job(&p);
	return (false);
}
