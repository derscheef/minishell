/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:23:28 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/28 18:14:12 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(char *input, t_main *main)
{
	main->exit_code = 69;
	if (ft_strncmp(input, "clear", 5) == 0)
		main->exit_code = clear_term();
	else if (ft_strncmp(input, "exit", 4) == 0)
		main->exit_code = exit_routine();
	else if (ft_strncmp(input, "echo", 4) == 0)
		main->exit_code = execute_echo(input);
	else if (ft_strncmp(input, "pwd", 3) == 0)
		main->exit_code = print_pwd();
	else if (ft_strncmp(input, "cd", 2) == 0)
		main->exit_code = exec_cd(input);
	else if (ft_strncmp(input, "export", 6) == 0)
		main->exit_code = exec_export(input, main);
	else if (ft_strncmp(input, "unset", 5) == 0)
		main->exit_code = exec_unset(input, main);
	else if (ft_strncmp(input, "env", 3) == 0)
		main->exit_code = print_env(main);
	else if (ft_strncmp(input, "", 1) == 0)
		;
	else
		ft_putstr("Command not found\n");
}
// printf("exit code: %d\n", main->exit_code);
