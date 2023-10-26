/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:50 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/26 11:53:17 by ndivjak          ###   ########.fr       */
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
		destroy_tokens(main->lexer.tokens);
}

void	routine(t_main *main)
{
	while (true)
	{
		main->input = readline("minishell> ");
		if (!main->input)
			exit_routine();
		add_history(main->input);
		lexer(main->input, ft_strlen(main->input), &main->lexer);
		if (!main->lexer.tokens)
			exit_routine();
		exec(main->input);
		reset_routine(main);
	}
}
