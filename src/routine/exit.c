/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:43:09 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/09 16:11:02 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	exit_routine(t_main *p)
{
	destroy_env_list(p->env_list);
	if (p->lexer.ntoks > 0)
	{
		p->lexer.ntoks = 0;
		destroy_tokens(p->lexer.tokens);
		if (p->ast)
			destroy_ast(p->ast);
	}
	if (p->input)
		free(p->input);
	if (p->prompt)
		free(p->prompt);
	exit(p->exit_code);
}
