/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:20:10 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/25 14:23:39 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_list(t_env_node *env_list)
{
	t_env_node	*temp;

	temp = env_list;
	while (temp != NULL)
	{
		printf("%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
}
