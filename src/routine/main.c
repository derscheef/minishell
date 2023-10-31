/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:50 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/31 11:49:53 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"
#include "routine.h"
#include "utils.h"

// 1. Read input from readline
// 2. Parse input
// 3. Execute command
// 4. Print output

static void	reset_routine(t_main *main)
{
	if (main->lexer.ntoks > 0)
	{
		main->lexer.ntoks = 0;
		destroy_tokens(main->lexer.tokens);
		if (main->ast)
			destroy_ast(main->ast);
	}
}

void	routine(t_main *main)
{
	while (true)
	{
		main->input = readline("minishell> ");
		if (!main->input)
			exit_routine(main->input, NULL);
		add_history(main->input);
		lexer(main->input, ft_strlen(main->input), main);
		// if (main->lexer.ntoks == 0)
		// {
		// 	reset_routine(main);
		// 	continue ;
		// }
		parse(main);
		execute(main);
		reset_routine(main);
	}
}
