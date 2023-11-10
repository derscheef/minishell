/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:23:14 by yscheef           #+#    #+#             */
/*   Updated: 2023/11/10 14:38:40 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_key(const char *key)
{
	if (!key || !*key || !(ft_isalpha(*key) || *key == '_'))
		return (0);
	while (*++key)
		if (!(ft_isalnum(*key) || *key == '_'))
			return (0);
	return (1);
}

static char	*extract_key_value(char **input, char **value)
{
	char	*eq_pos;
	char	*space_pos;

	eq_pos = ft_strchr(*input, '=');
	if (eq_pos)
	{
		*eq_pos = '\0';
		*value = ft_strtrim(eq_pos + 1, " \t\n");
	}
	else
	{
		space_pos = ft_strchr(*input, ' ');
		if (space_pos)
		{
			*space_pos = '\0';
			*value = ft_strtrim(space_pos + 1, " \t\n");
		}
	}
	return (ft_strtrim(*input, " \t\n"));
}

int	exec_export(char *input, t_internal_cmd *main)
{
	char	*value;
	char	*key;

	value = NULL;
	if (!input || !main)
		return (1);
	input += 6;
	while (*input == ' ' || *input == '\t')
		input++;
	key = extract_key_value(&input, &value);
	if (!key || !is_valid_key(key))
	{
		free(key);
		if (value)
			free(value);
		return (ft_putendl_fd(" not a valid identifier", 2), 1);
	}
	if (!value)
		value = "";
	modify_or_add_env(main, key, value);
	free(key);
	if (*value)
		free(value);
	return (0);
}
