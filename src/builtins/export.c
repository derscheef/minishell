/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:23:14 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/30 22:17:36 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_listadd_back(t_env_node **lst, t_env_node *new)
{
	t_env_node	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

static void	modify_or_add_env(t_internal_cmd *main, char *key, char *value)
{
	t_env_node	*current;
	t_env_node	*new_node;

	current = main->env_node;
	while (current)
	{
		if (current->key && key && ft_strlen(current->key) == ft_strlen(key)
			&& ft_strncmp(current->key, key, ft_strlen(key)) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			return ;
		}
		current = current->next;
	}
	new_node = (t_env_node *)ft_calloc(1, sizeof(t_env_node));
	if (!new_node)
	{
		perror("Error allocating memory for new env node");
		exit_routine("1", NULL);
	}
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	env_listadd_back(&(main->env_node), new_node);
}

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
