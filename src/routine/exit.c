/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:31 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/23 18:47:57 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

// TODO: Change to rl_clear_history from clear_history
void	exit_routine(void)
{
	clear_history();
	exit(1);
}
