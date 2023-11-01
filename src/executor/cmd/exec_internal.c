/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_internal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:14:12 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/28 19:45:08 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_builtin(char *input)
{
	if (!ft_strncmp(input, "clear", 5))
		return (true);
	else if (!ft_strncmp(input, "exit", 4))
		return (true);
	else if (!ft_strncmp(input, "echo", 4))
		return (true);
	else if (!ft_strncmp(input, "pwd", 3))
		return (true);
	else if (!ft_strncmp(input, "cd", 2))
		return (true);
	else if (!ft_strncmp(input, "export", 6))
		return (true);
	else if (!ft_strncmp(input, "unset", 5))
		return (true);
	else if (!ft_strncmp(input, "env", 3))
		return (true);
	else
		return (false);
}

bool	execute_internal_command(t_internal_cmd *p)
{
	size_t i = 0;
	char *tmp;

	while(i < p->ac)
	{
		p->av[i] = replace_env_var(p->av[i], p->env_node, *p->exit_code);
		tmp = remove_quotes(p->av[i]);
		free(p->av[i]);
		p->av[i] = tmp;
		i++;
	}
	if (is_builtin(p->av[0]))
		execute_builtin(p);
	else
		execute_external(p);
	return (false);
}
