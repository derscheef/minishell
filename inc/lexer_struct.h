/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:09:22 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 18:11:28 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_STRUCT_H
# define LEXER_STRUCT_H

# include "stddef.h"

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
	CHAR_DGREATER,
	CHAR_DLESSER,
	CHAR_LESSER = '<',
	CHAR_NULL = 0,
	TOKEN = -1,
}						t_token_type;

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

#endif