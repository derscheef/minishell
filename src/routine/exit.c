/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:43:09 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/01 17:16:13 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	exit_routine(t_main *p)
{
	if (p->lexer.tokens)
		destroy_tokens(p->lexer.tokens);
	destroy_env_list(p->env_list);
	if (p->lexer.ntoks > 0)
	{
		p->lexer.ntoks = 0;
		destroy_tokens(p->lexer.tokens);
		if (p->ast)
			destroy_ast(p->ast);
	}
	exit(p->exit_code);
}
