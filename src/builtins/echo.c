/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:48:26 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/27 11:00:10 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_echo(char *input)
{
	int	i;
	int	print_newline;

	i = 4;
	print_newline = 1;
	while (input[i] == ' ')
	{
		i++;
	}
	if (ft_strncmp(input + i, "-n", 2) == 0)
	{
		print_newline = 0;
		i += 2;
	}
	while (input[i] == ' ')
	{
		i++;
	}
	ft_putstr(input + i);
	if (print_newline)
	{
		ft_putchar('\n');
	}
	return (0);
}
