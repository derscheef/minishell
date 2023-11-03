/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:03:46 by yscheef           #+#    #+#             */
/*   Updated: 2023/11/03 17:19:02 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_builtin(char *exit_code_str, t_internal_cmd *p, t_main *main)
{
	if (p && p->ac > 2)
	{
		ft_putendl_fd(" too many arguments", 2);
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
			main->exit_code = 255;
			ft_putendl_fd(" numeric argument required", 2);
			break ;
		}
		exit_code_str++;
	}
	clear_history();
	return (exit_routine(main));
}
