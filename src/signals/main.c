/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:59 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/19 23:23:35 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

// ctrl-C
void	sigint_handler(int signum)
{
	(void)signum;
	write(1, "\nminishell> ", 13);
	rl_on_new_line();
	rl_redisplay();
}

// ctrl-backslash
void	sigquit_handler(int signum)
{
	(void)signum;
	exit(1);
}

void	handle_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}
