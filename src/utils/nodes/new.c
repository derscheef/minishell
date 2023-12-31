/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:48:16 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/03 17:48:38 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*new_node(char *data, t_node_type type)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (data)
		node->data = data;
	else
		node->data = NULL;
	node->type = type;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
