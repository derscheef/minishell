/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_or_add_env_var.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:37:43 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/10 14:38:46 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_listadd_back(t_env_node **lst, t_env_node *new)
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

void	modify_or_add_env(t_internal_cmd *main, char *key, char *value)
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
		return ;
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	env_listadd_back(&(main->env_node), new_node);
}
