/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:23:28 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/25 12:31:38 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(char *input)
{
	if (ft_strncmp(input, "clear", 5) == 0)
		clear_term();
	else if (ft_strncmp(input, "exit", 4) == 0)
		exit_routine();
	else if (ft_strncmp(input, "echo", 4) == 0)
		execute_echo(input);
	else if (ft_strncmp(input, "pwd", 3) == 0)
		print_pwd();
	else if (ft_strncmp(input, "cd", 2) == 0)
		ft_putstr("cd\n");
	else if (ft_strncmp(input, "export", 6) == 0)
		ft_putstr("export\n");
	else if (ft_strncmp(input, "unset", 5) == 0)
		ft_putstr("unset\n");
	else if (ft_strncmp(input, "env", 3) == 0)
		print_env();
	else if (ft_strncmp(input, "", 1) == 0)
		;
	else
		ft_putstr("Command not found\n");
}
