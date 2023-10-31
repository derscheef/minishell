/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:52:26 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/31 17:03:28 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ast.h"
# include "env_list.h"

typedef struct s_main
{
	t_lexer		lexer;
	t_node		*ast;
	t_env_node	*env_list;
	int			exit_code;

	char		*input;
	char		*tmp;
}				t_main;

#endif
