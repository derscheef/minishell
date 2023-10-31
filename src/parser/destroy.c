/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:41:29 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/28 19:45:04 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_ast(t_node *node)
{
	if (!node)
		return ;
	destroy_ast(node->left);
	destroy_ast(node->right);
	free(node->data);
	free(node);
}
