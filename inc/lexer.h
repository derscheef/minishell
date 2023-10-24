/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:44:51 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/24 12:43:16 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

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
	CHAR_WHITESPACE = ' ',
	CHAR_ESCAPESEQUENCE = '\\',
	CHAR_TAB = '\t',
	CHAR_NEWLINE = '\n',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_NULL = 0,
	TOKEN = -1,
}						t_token_type;

enum					e_state
{
	STATE_IN_DQUOTE,
	STATE_IN_QUOTE,
	STATE_IN_ESCAPESEQ,
	STATE_GENERAL,
};

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

// Return status code
int						lexer(char *str, size_t size, t_lexer *lexer);

// Token functions
void					init_token(t_token *token, int datasize);
void					destroy_tokens(t_token *token);

#endif
