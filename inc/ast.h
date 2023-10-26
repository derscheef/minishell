/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:37:38 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/26 16:38:47 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef enum e_node_type
{
	NODE_PIPE = (1 << 0),
	NODE_BCKGRND = (1 << 1),
	NODE_SEQ = (1 << 2),
	NODE_REDIRECT_IN = (1 << 3),
	NODE_REDIRECT_OUT = (1 << 4),
	NODE_CMDPATH = (1 << 5),
	NODE_ARGUMENT = (1 << 6),
	NODE_DATA = (1 << 7),
}					t_node_type;

typedef struct s_node
{
	t_node_type		type;
	char			*data;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

#endif
