/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:46:20 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 22:16:48 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_input(t_internal_cmd *p)
{
	char	*input;
	int		i;

	i = 0;
	input = NULL;
	while (p->av[i])
	{
		if (i == 0)
			input = ft_strdup(p->av[i]);
		else
			input = ft_strjoin(input, p->av[i]);
		if (p->av[i + 1])
			input = ft_strjoin(input, " ");
		i++;
	}
	return (input);
}

int	handle_fd(t_internal_cmd *p)
{
	int	fd;

	fd = 1;
	if (!p->is_stdout)
		fd = STDOUT_FILENO;
	return (fd);
}

void	execute_builtin(t_internal_cmd *p)
{
	int		fd;
	char	*input;

	input = convert_input(p);
	fd = handle_fd(p);
	if (ft_strncmp(input, "clear", 5) == 0)
		*p->exit_code = clear_term();
	else if (ft_strncmp(input, "exit", 4) == 0)
		exit_routine(input, p);
	else if (ft_strncmp(input, "echo", 4) == 0)
		*p->exit_code = execute_echo(p, fd);
	else if (ft_strncmp(input, "pwd", 3) == 0)
		*p->exit_code = print_pwd(fd);
	else if (ft_strncmp(input, "cd", 2) == 0)
		*p->exit_code = exec_cd(input);
	else if (ft_strncmp(input, "export", 6) == 0)
		*p->exit_code = exec_export(input, p);
	else if (ft_strncmp(input, "unset", 5) == 0)
		*p->exit_code = exec_unset(input, p);
	else if (ft_strncmp(input, "env", 3) == 0)
		*p->exit_code = print_env(p, fd);
	else
		ft_putstr("Command not found\n");
}
