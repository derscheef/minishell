/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:03:46 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/30 19:15:01 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Change to rl_clear_history from clear_history
void	exit_routine(char *exit_code_str)
{
	int	exit_code;

	if (!exit_code_str)
		return (exit(0));
	exit_code = ft_atoi(exit_code_str);
	while (*exit_code_str)
	{
		if (!ft_isdigit(*exit_code_str) && !(*exit_code_str == '+'
				|| *exit_code_str == '-'))
		{
			exit_code = 255;
			perror("numeric argument required");
			break ;
		}
		exit_code_str++;
	}
	clear_history();
	return (exit(exit_code));
}
