/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:38:05 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/26 16:29:50 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	print_env(t_main *main)
{
	t_env_node	*current;

	if (!main)
		return ;
	current = main->env_list;
	while (current)
	{
		printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
}
