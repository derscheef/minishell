/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:46:20 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/10 12:48:23 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_input(t_internal_cmd *p)
{
	char	*input;
	char	*temp;
	int		i;

	i = 0;
	input = NULL;
	while (p->av[i])
	{
		if (i == 0)
			input = ft_strdup(p->av[i]);
		else
		{
			temp = ft_strjoin(input, p->av[i]);
			free(input);
			input = temp;
		}
		if (p->av[i + 1])
		{
			temp = ft_strjoin(input, " ");
			free(input);
			input = temp;
		}
		i++;
	}
	return (input);
}

// TODO: this input free is a workaround
// any exit inside the builtin command will still result in a memory leak
// this is because the input is not freed on exit
// Option 1: rewrite the builtin commands to not use input
// Option 2: free input on exit

void	execute_cmd_based_on_input(char *input, t_internal_cmd *p, int fd)
{
	if (ft_strncmp(input, "clear", 5) == 0)
		*p->exit_code = clear_term();
	else if (ft_strncmp(input, "exit", 4) == 0)
		exit_builtin(input, p, p->main);
	else if (ft_strncmp(input, "echo", 4) == 0)
		*p->exit_code = execute_echo(p, fd);
	else if (ft_strncmp(input, "pwd", 3) == 0)
		*p->exit_code = print_pwd(fd);
	else if (ft_strncmp(input, "cd", 2) == 0)
		*p->exit_code = exec_cd(p);
	else if (ft_strncmp(input, "export", 6) == 0)
		*p->exit_code = exec_export(input, p);
	else if (ft_strncmp(input, "unset", 5) == 0)
		*p->exit_code = exec_unset(input, p);
	else if (ft_strncmp(input, "env", 3) == 0)
		*p->exit_code = print_env(p, fd);
	free(input);
}

void	execute_builtin(t_internal_cmd *p)
{
	int		fd;
	char	*input;
	int		original_stdout;
	int		original_stdin;

	original_stdout = dup(STDOUT_FILENO);
	original_stdin = dup(STDIN_FILENO);
	input = convert_input(p);
	fd = handle_fd(p);
	if (fd == -1)
	{
		ft_putstr_fd(" No such file or directory\n", STDERR_FILENO);
		*p->exit_code = 1;
		restore_fds(original_stdout, original_stdin);
	}
	else
	{
		restore_fds(original_stdout, original_stdin);
		execute_cmd_based_on_input(input, p, fd);
	}
}
