/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:59 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/23 19:43:51 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// ctrl-C
void	sigint_handler(int signum)
{
	if (signum == SIGUSR1)
		exit(EXIT_FAILURE);
	if (signum == SIGINT)
	{
		ft_putstr("\n");
		// rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (signum == SIGTERM)
	{
		exit(1);
	}
}

// ctrl-backslash
void	sigquit_handler(int signum)
{
	(void)signum;
	exit(1);
}

void	handle_signals(void)
{
	struct termios	term;
	struct termios	oldterm;

	tcgetattr(STDIN_FILENO, &oldterm);
	term = oldterm;
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}
