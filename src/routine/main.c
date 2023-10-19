/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:50 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/19 17:23:44 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "routine.h"

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
		tokens = lexer(input);
		free(tokens);
	}
}
