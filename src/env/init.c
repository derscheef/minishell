/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:14:46 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/26 11:43:20 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_lstadd_back(t_env_node **lst, t_env_node *new)
{
	t_env_node	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

t_env_node	*new_env_node(char *str)
{
	t_env_node	*node;
	char		*delimiter;

	node = malloc(sizeof(t_env_node));
	if (!node)
		return (NULL);
	delimiter = ft_strchr(str, '=');
	node->key = ft_substr(str, 0, delimiter - str);
	node->value = ft_strdup(delimiter + 1);
	node->next = NULL;
	return (node);
}

t_env_node	*init_env_list(char **env)
{
	t_env_node	*head;
	t_env_node	*temp;
	int			i;

	head = NULL;
	i = 0;
	while (env[i])
	{
		temp = new_env_node(env[i]);
		if (!head)
			head = temp;
		else
			env_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}
