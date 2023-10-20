/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:50 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/20 16:18:29 by ndivjak          ###   ########.fr       */
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

static void	reset_routine(t_main main)
{
	free(main.tokens);
}

void	routine(void)
{
	t_main	main;

	while (true)
	{
		main.input = readline("minishell> ");
		if (!main.input)
			exit_routine();
		add_history(main.input);
		main.tokens = lexer(main.input);
		if (!main.tokens)
			exit_routine();
		print_tokens(main.tokens);
		reset_routine(main);
	}
}
