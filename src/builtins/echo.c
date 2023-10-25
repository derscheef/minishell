/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:48:26 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/25 12:37:27 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_echo(char *input)
{
	int	i;
	int	print_newline;

	i = 4;
	print_newline = 1;
	while (input[i] == ' ')
	{
		i++;
	}
	// Check if next token is "-n".
	if (ft_strncmp(input + i, "-n", 2) == 0)
	{
		print_newline = 0; // If "-n" is found, we don't print a newline.
		i += 2;
	}
	// Skip spaces after "-n", if it was found.
	while (input[i] == ' ')
	{
		i++;
	}
	// Print the rest of the input string.
	ft_putstr(input + i);
	// If we're supposed to print a newline, do it.
	if (print_newline)
	{
		ft_putchar('\n');
	}
}
