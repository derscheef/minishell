/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:59 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/19 14:13:17 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal.h"

// ctrl-c
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
	signall(SIGKILL, sigkill_handler);
	signal(SIGQUIT, sigquit_handler);
}
