/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:56:35 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/25 18:09:00 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

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

bool				parse(t_main *main);

#endif