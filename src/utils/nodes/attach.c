/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attach.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:55:28 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/10 17:09:14 by ndivjak          ###   ########.fr       */
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

void	attach_to_last_node(t_node *root, t_node *left, t_node *right)
{
	t_node	*last_node_left;
	t_node	*last_node_right;
	t_node	*root_copy;

	last_node_left = root;
	last_node_right = root;
	root_copy = root;
	if (!root)
		return ;
	while (root->left)
	{
		root = root->left;
		last_node_left = root;
	}
	root = root_copy;
	while (root->right)
	{
		root = root->right;
		last_node_right = root;
	}
	attach_node(last_node_left, left, last_node_left->right);
	attach_node(last_node_right, last_node_right->left, right);
}
