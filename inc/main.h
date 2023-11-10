/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:52:26 by yscheef           #+#    #+#             */
/*   Updated: 2023/11/10 14:13:49 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ast.h"
# include "env_list.h"
# include "lexer_struct.h"

typedef struct s_main
{
	t_lexer		lexer;
	t_node		*ast;
	t_env_node	*env_list;
	int			exit_code;

	char		*input;
	char		*tmp;
	char		*prompt;
}				t_main;

#endif
