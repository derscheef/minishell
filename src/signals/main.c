/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:59 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/19 18:26:43 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	sigint_handler(int signum)
{
	(void)signum;
	printf("SIGINT\n");
}

// ctrl-D
void	sigquit_handler(int signum)
{
	(void)signum;
	printf("SIGQUIT\n");
}

void	sigterm_handler(int signum)
{
	(void)signum;
	printf("SIGTERM\n");
}

void	sigkill_handler(int signum)
{
	(void)signum;
	printf("SIGKILL\n");
}

void	handle_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGTERM, sigterm_handler);
	signal(SIGKILL, sigkill_handler);
}
