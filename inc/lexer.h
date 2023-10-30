/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:44:51 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 13:12:24 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "env_list.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

typedef enum e_token_type
{
	CHAR_GENERAL = -1,
	CHAR_PIPE = '|',
	CHAR_AMPERSAND = '&',
	CHAR_QOUTE = '\'',
	CHAR_DQUOTE = '\"',
	CHAR_SEMICOLON = ';',
	CHAR_SPACE = ' ',
	CHAR_ESCAPESEQUENCE = '\\',
	CHAR_TAB = '\t',
	CHAR_NEWLINE = '\n',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_NULL = 0,
	TOKEN = -1,
}						t_token_type;

typedef enum e_state
{
	STATE_IN_DQUOTE,
	STATE_IN_QUOTE,
	STATE_IN_ESCAPESEQ,
	STATE_GENERAL,
}						t_state;

typedef struct s_token	t_token;

struct					s_token
{
	char				*data;
	t_token_type		type;
	t_token				*next;
};
typedef struct s_lexer
{
	t_token				*tokens;
	size_t				ntoks;
}						t_lexer;

typedef struct s_lexer_program
{
	t_lexer				*lexer;
	t_token				*token;
	t_env_node			*env_list;
	t_state				state;
	size_t				i;
	size_t				j;
	size_t				str_size;
	char				*str;

	char				c;
	t_token_type		ch_type;
}						t_lexer_program;

// Return status code
bool					lexer(char *str, size_t size, t_lexer *lexer,
							t_env_node *env_list);

t_token_type			get_char_type(char c);

// Token functions
bool					init_token(t_token *token, int datasize);
void					destroy_tokens(t_token *token);

// State handling
bool					handle_general_state(t_lexer_program *p);
bool					handle_quote_state(t_lexer_program *p, char quote);

#endif
