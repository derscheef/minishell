/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:23:14 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/30 15:22:08 by yscheef          ###   ########.fr       */
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
		exit_routine();
	}
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	env_listadd_back(&(main->env_node), new_node);
}

int	exec_export(char *input, t_internal_cmd *main)
{
	char	*eq_pos;
	char	*key;
	char	*value;

	if (!input || !main)
		return (1);
	input += 6;
	eq_pos = ft_strchr(input, '=');
	if (!eq_pos)
		return (ft_putendl_fd("Error: export format should be KEY=VALUE", 2),
			2);
	*eq_pos = '\0';
	key = ft_strtrim(input, " \t\n");
	value = ft_strtrim(eq_pos + 1, " \t\n");
	modify_or_add_env(main, key, value);
	free(key);
	free(value);
	return (0);
}
