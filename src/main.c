/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:25:58 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/08 11:43:32 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_main	main;

	(void)argc;
	(void)argv;
	main.exit_code = 0;
	main.lexer.ntoks = 0;
	env_init(&main, env);
	handle_signals();
	routine(&main);
	return (0);
}
