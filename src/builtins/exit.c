/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:03:46 by yscheef           #+#    #+#             */
/*   Updated: 2023/11/16 22:19:00 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_builtin(char *exit_code_str, t_internal_cmd *p, t_main *main)
{
	if (p && p->ac > 2)
	{
		main->exit_code = 1;
		ft_putendl_fd(" too many arguments", STDERR_FILENO);
		return (exit_routine(main));
	}
	if (p)
		exit_code_str = p->av[1];
	if (!exit_code_str)
		exit_code_str = "1";
	main->exit_code = ft_atoi(exit_code_str);
	while (*exit_code_str)
	{
		if (!ft_isdigit(*exit_code_str) && !(*exit_code_str == '+'
				|| *exit_code_str == '-'))
		{
			main->exit_code = 2;
			ft_putendl_fd(" numeric argument required", STDERR_FILENO);
			break ;
		}
		exit_code_str++;
	}
	clear_history();
	return (exit_routine(main));
}
