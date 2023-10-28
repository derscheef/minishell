/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:48:25 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/28 19:37:14 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_list_size(t_env_node *env)
{
	size_t	i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

static char	**parse_env(t_env_node *env)
{
	char	**envp;
	size_t	i;

	i = get_list_size(env);
	envp = ft_calloc(i + 1, sizeof(char *));
	if (!envp)
		return (NULL);
	i = 0;
	while (env)
	{
		envp[i] = ft_strjoin(ft_strjoin(env->key, "="), env->value);
		i++;
		env = env->next;
	}
	return (envp);
}

static void	free_env(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

bool	execute(t_main *main)
{
	t_executor	program;

	if (!main->ast)
		return (true);
	program.env = parse_env(main->env_list);
	program.node = main->ast;
	execute_job(&program);
	free_env(program.env);
	return (false);
}
