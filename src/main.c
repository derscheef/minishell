/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:25:58 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/28 17:51:11 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_env_node	*env_list;
	t_main		main;

	env_list = init_env_list(env);
	if (!env_list)
		return (1);
	handle_signals();
	routine(&main);
	printf("argc: %d\n", argc);
	printf("argv: %s\n", argv[0]);
	return (0);
}
