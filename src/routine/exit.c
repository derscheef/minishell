/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:31 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/19 13:43:47 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

// TODO: Change to rl_clear_history from clear_history
void	exit_routine(void)
{
	clear_history();
	exit(1);
}
