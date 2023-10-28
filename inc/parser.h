/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:56:35 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/28 19:42:12 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include "routine.h"

typedef struct s_parse_program
{
	t_token	*cur_token;
	t_node	*ast;
}			t_parse_program;

bool		parse(t_main *main);
void		destroy_ast(t_node *node);
bool		consume_token(t_token_type type, char **strbuffer,
				t_parse_program *p);

// Job
t_node		*parse_job(t_parse_program *p);
t_node		*parse_job1(t_parse_program *p);

// Cmd
t_node		*parse_cmd(t_parse_program *p);
t_node		*parse_cmd1(t_parse_program *p);
t_node		*parse_cmd2(t_parse_program *p);
t_node		*parse_simple_cmd(t_parse_program *p);

// Token list
t_node		*parse_tokenlist(t_parse_program *p);

#endif
