/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:52:26 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/27 10:57:09 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ast.h"
# include "lexer.h"

typedef struct s_env_node
{
	char				*key;
	char				*value;
	struct s_env_node	*next;
}						t_env_node;

typedef struct s_main
{
	t_lexer				lexer;
	t_node				*ast;
	t_env_node			*env_list;
	int					exit_code;

	char				*input;
}						t_main;

#endif
