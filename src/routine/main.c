/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:50 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/24 16:28:44 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 1. Read input from readline
// 2. Parse input
// 3. Execute command
// 4. Print output

void	routine(void)
{
	char	*input;
	char	**tokens;

	while (true)
	{
		input = readline("minishell> ");
		if (!input)
			exit_routine();
		add_history(input);
		exec(input);
		tokens = lexer(input);
		free(tokens);
	}
}
