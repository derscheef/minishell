/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:18:15 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 14:48:37 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "utils.h"

char	*replace_env_var(char *str, t_env_node *env_list)
{
	char *env_var;
	char *end_of_var;
	char *start;
	char *end;
	char *var;

	env_var = str;
	while ((env_var = skip_to_set(env_var, "$\'")))
		if (!*env_var)
			return (str);
		else if (*env_var == '\'')
			env_var = skip_to_set(env_var + 1, "\'");
		else if (*env_var == '$')
			break ;
	end_of_var = skip_to_set(env_var, " \"\'\t\n");
	start = ft_substr(str, 0, env_var - str);
	end = ft_substr(str, end_of_var - str, ft_strlen(str));
	var = ft_substr(env_var, 0, end_of_var - env_var);
	while (env_list)
	{
		if (!ft_strcmp(env_list->key, var + 1))
		{
			free(var);
			var = ft_strdup(env_list->value);
			break ;
		}
		env_list = env_list->next;
	}
	free(str);
	str = ft_strjoin(start, var);
	free(start);
	free(var);
	str = ft_strjoin(str, end);
	free(end);
	return (replace_env_var(str, env_list));
}