/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:59 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/19 17:17:14 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	sigint_handler(int signum)
{
	(void)signum;
	printf("SIGINT\n");
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
