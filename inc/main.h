/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:52:26 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/30 14:55:14 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ast.h"
# include "env_list.h"
# include "lexer.h"

typedef struct s_main
{
	t_lexer		lexer;
	t_node		*ast;
	t_env_node	*env_list;
	int			exit_code;

	char		*input;
}				t_main;

#endif
