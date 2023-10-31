/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:57:24 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 20:43:03 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef enum e_node_type
{
	NODE_PIPE,
	NODE_BCKGRND,
	NODE_SEQ,
	NODE_REDIRECT_IN,
	NODE_REDIRECT_IN_HEREDOC,
	NODE_REDIRECT_OUT_APPEND,
	NODE_REDIRECT_OUT,
	NODE_CMDPATH,
	NODE_ARGUMENT,
	NODE_DATA,
}					t_node_type;

typedef struct s_node
{
	t_node_type		type;
	char			*data;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

#endif
