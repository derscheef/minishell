/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:40:26 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/26 16:46:26 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_key(char *input)
{
	// Assuming the input format is "unset KEY", we'll skip the first 6 chars
	return (ft_strtrim(input + 6, " \t\n\r\v\f"));
	// remove any surrounding whitespace
}

void	remove_env_node(t_env_node **head, char *key)
{
	t_env_node	*prev;
	t_env_node	*curr;

	prev = NULL;
	curr = *head;
	while (curr)
	{
		if (!ft_strncmp(curr->key, key, ft_strlen(key)))
		{
			if (prev)
				prev->next = curr->next;
			else
				*head = curr->next;
			free(curr->key);
			free(curr->value);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	exec_unset(char *input, t_main *main)
{
	char	*key;

	key = parse_key(input);
	if (key)
	{
		remove_env_node(&main->env_list, key);
		free(key);
	}
}
