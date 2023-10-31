/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:40:26 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/31 17:41:33 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_key(char *input)
{
	return (ft_strtrim(input + 6, " \t\n\r\v\f"));
}

void	remove_env_node(t_env_node **head, char *key)
{
	t_env_node	*prev;
	t_env_node	*curr;

	prev = NULL;
	curr = *head;
	while (curr)
	{
		if (!ft_strncmp(curr->key, key, ft_strlen(key))
			|| !ft_strncmp(curr->value, key, ft_strlen(key)))
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

int	exec_unset(char *input, t_internal_cmd *main)
{
	char	*key;

	if (main->av[1] == NULL)
		return (0);
	key = parse_key(input);
	if (key)
	{
		remove_env_node(&main->env_node, key);
		free(key);
	}
	return (0);
}
