/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:38:05 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/30 15:26:43 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	print_env(t_internal_cmd *main, int fd)
{
	t_env_node	*current;

	if (!main)
		return (1);
	current = main->env_node;
	while (current)
	{
		ft_putstr_fd(current->key, fd);
		ft_putchar_fd('=', fd);
		ft_putstr_fd(current->value, fd);
		ft_putchar_fd('\n', fd);
		current = current->next;
	}
	return (0);
}
