/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:18:15 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 15:57:33 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "utils.h"

typedef struct s_env_var
{
	char	*start;
	char	*end;
	char	*var;
}			t_env_var;

static bool	is_env_var(char *str, t_env_node *env_list)
{
	char	*var;
	char	*end_of_var;

	end_of_var = skip_to_set(str, " \"\'\t\n");
	var = ft_substr(str, 0, end_of_var - str);
	if (get_env_var(var, env_list))
		return (free(var), true);
	return (false);
}

static void	init_env_var(char *str, char *start_var, t_env_var *env_var)
{
	char	*end_of_var;

	end_of_var = skip_to_set(start_var, " \"\'\t\n");
	env_var->start = ft_substr(str, 0, start_var - str);
	env_var->end = ft_substr(str, end_of_var - str, ft_strlen(str));
	env_var->var = ft_substr(start_var, 0, end_of_var - start_var);
}

static char	*rebuild_string(char *str, t_env_var *env, t_env_node *env_list)
{
	char	*tmp;

	tmp = get_env_var(env->var + 1, env_list);
	if (tmp)
	{
		free(env->var);
		env->var = ft_strdup(tmp);
	}
	free(str);
	str = ft_strjoin(env->start, env->var);
	free(env->start);
	free(env->var);
	str = ft_strjoin(str, env->end);
	free(env->end);
	return (str);
}

char	*replace_env_var(char *str, t_env_node *env_list)
{
	char		*env_var;
	char		*tmp;
	t_env_var	env;

	env_var = skip_to_set(str, "$\'");
	while (env_var)
	{
		if (!*env_var)
			return (str);
		else if (*env_var == '\'')
			env_var = skip_to_set(env_var + 1, "\'");
		else if (*env_var == '$')
		{
			if (is_env_var(env_var + 1, env_list))
				break ;
			env_var++;
		}
		env_var = skip_to_set(env_var, "$\'");
	}
	init_env_var(str, env_var, &env);
	str = rebuild_string(str, &env, env_list);
	return (replace_env_var(str, env_list));
}
