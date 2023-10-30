/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:03:46 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/30 22:25:09 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_routine(char *exit_code_str, t_internal_cmd *p)
{
	int	exit_code;

	if (p->av[2])
	{
		ft_putendl_fd(" too many arguments", 2);
		exit(1);
	}
	exit_code_str = p->av[1];
	if (!exit_code_str)
		return (exit(0));
	exit_code = ft_atoi(exit_code_str);
	while (*exit_code_str)
	{
		if (!ft_isdigit(*exit_code_str) && !(*exit_code_str == '+'
				|| *exit_code_str == '-'))
		{
			exit_code = 255;
			ft_putendl_fd(" numeric argument required", 2);
			break ;
		}
		exit_code_str++;
	}
	clear_history();
	return (exit(exit_code));
}
