/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:19:06 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/26 15:56:34 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_term(void)
{
	char	*clearstr;
	char	buffer[1024];
	int		success;

	success = tgetent(buffer, getenv("TERM"));
	if (success < 0)
	{
		perror("Could not access the termcap data base");
		exit(1);
	}
	clearstr = tgetstr("cl", NULL);
	if (clearstr == NULL)
	{
		perror("Could not get the clear string");
		exit(1);
	}
	tputs(clearstr, 0, putchar);
}
