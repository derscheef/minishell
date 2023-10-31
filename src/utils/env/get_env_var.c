/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:32:40 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 15:36:52 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "utils.h"

char	*get_env_var(char *key, t_env_node *env_list)
{
	while (env_list)
	{
		if (!ft_strcmp(env_list->key, key))
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}
