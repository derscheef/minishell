/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:19:06 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/24 16:53:35 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_term(void)
{
	char	*clearstr;
	char	buffer[1024];
	int		success;

	// Load the terminal capabilities
	success = tgetent(buffer, getenv("TERM"));
	if (success < 0)
	{
		perror("Could not access the termcap data base");
		exit(1);
	}
	// Get the string to clear the screen
	clearstr = tgetstr("cl", NULL);
	if (clearstr == NULL)
	{
		perror("Could not get the clear string");
		exit(1);
	}
	// Output the clear string to the terminal
	tputs(clearstr, 0, putchar);
	perror("Could not get the clear string");
}
