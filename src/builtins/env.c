/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:38:05 by yscheef           #+#    #+#             */
/*   Updated: 2023/11/10 12:38:15 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	print_env(t_internal_cmd *main, int fd)
{
	int	i;

	i = 0;
	if (!main)
		return (1);
	while (main->env[i])
	{
		ft_putstr_fd(main->env[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
	return (0);
}
