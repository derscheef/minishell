/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:18:15 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 15:42:12 by ndivjak          ###   ########.fr       */
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
}

char	*replace_env_var(char *str, char *env, t_env_node *env_list)
{
	char	*env_var;
	char	*end_of_var;
	char	*start;
	char	*end;
	char	*var;
	char	*tmp;

	env_var = str;
	while ((env_var = skip_to_set(env_var, "$\'")))
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
	end_of_var = skip_to_set(env_var, " \"\'\t\n");
	start = ft_substr(str, 0, env_var - str);
	end = ft_substr(str, end_of_var - str, ft_strlen(str));
	var = ft_substr(env_var, 0, end_of_var - env_var);
	tmp = get_env_var(var + 1, env_list);
	if (tmp)
	{
		free(var);
		var = ft_strdup(tmp);
	}
	free(str);
	str = ft_strjoin(start, var);
	free(start);
	free(var);
	str = ft_strjoin(str, end);
	free(end);
	return (replace_env_var(str, env_list));
}
