/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:10:43 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/24 16:13:19 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token_type	get_char_type(char c)
{
	if (c == '\'')
		return (CHAR_QOUTE);
	if (c == '\"')
		return (CHAR_DQUOTE);
	if (c == '|')
		return (CHAR_PIPE);
	if (c == '&')
		return (CHAR_AMPERSAND);
	if (c == ' ')
		return (CHAR_SPACE);
	if (c == ';')
		return (CHAR_SEMICOLON);
	if (c == '\\')
		return (CHAR_ESCAPESEQUENCE);
	if (c == '\t')
		return (CHAR_TAB);
	if (c == '\n')
		return (CHAR_NEWLINE);
	if (c == '>')
		return (CHAR_GREATER);
	if (c == '<')
		return (CHAR_LESSER);
	if (c == 0)
		return (CHAR_NULL);
	return (CHAR_GENERAL);
}
