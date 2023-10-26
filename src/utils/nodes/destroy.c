/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:01:25 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/26 14:33:33 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_node(t_node *node)
{
	if (!node)
		return ;
	if (node->type & NODE_DATA)
		free(node->data);
	destroy_node(node->left);
	destroy_node(node->right);
	free(node);
}
