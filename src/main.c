/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:25:58 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/26 11:48:43 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_main	main;

	env_init(&main, env);
	handle_signals();
	routine(&main);
	printf("argc: %d", argc);
	printf("argv: %s", argv[0]);
	return (0);
}
