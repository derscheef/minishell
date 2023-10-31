/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attach.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:55:28 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/26 14:33:36 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	attach_node(t_node *root, t_node *left, t_node *right)
{
	if (!root)
		return ;
	root->left = left;
	root->right = right;
}
