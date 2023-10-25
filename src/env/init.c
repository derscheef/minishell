/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:14:46 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/25 14:16:51 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_node	*init_env_list(char **env)
{
	t_env_node *head;
	t_env_node *temp;
	char *key;
	char *value;
	int i;
	t_env_node *node;

	head = NULL;
	temp = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		key = strtok(env[i], "=");
		value = strtok(NULL, "=");
		node = malloc(sizeof(t_env_node));
		node->key = strdup(key);
		node->value = strdup(value);
		node->next = NULL;
		if (head == NULL)
		{
			head = node;
			temp = node;
		}
		else
		{
			temp->next = node;
			temp = temp->next;
		}
		i++;
	}
	return (head);
}
