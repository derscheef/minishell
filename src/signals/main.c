/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:59 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/24 15:38:37 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	configure_terminal(void)
{
	struct termios	term;

	// Get the current terminal settings
	tcgetattr(STDIN_FILENO, &term);
	// Modify the settings
	term.c_lflag &= ~(ECHOCTL);
	// Set the new terminal settings
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// ctrl-C
void	handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	configure_terminal();
}

// ctrl-backslash
void	handle_sigquit(int sig)
{
	(void)sig;
	exit(1);
}

void	handle_eof(void)
{
	// Exit the shell
	exit(0);
}

void	handle_signals(void)
{
	struct sigaction sa_int, sa_quit;
	configure_terminal();
	sa_int.sa_handler = handle_sigint;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_int, NULL);
	sa_quit.sa_handler = handle_sigquit;
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa_quit, NULL);
}
