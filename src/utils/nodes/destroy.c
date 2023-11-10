/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:01:25 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/10 17:45:51 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_node(t_node *node)
{
	if (!node)
		return ;
	if (node->data)
		free(node->data);
	destroy_node(node->left);
	destroy_node(node->right);
	free(node);
}
