/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:00:41 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/24 16:13:55 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "utils.h"

static void	set_token(t_lexer_program *p, char c, t_state state)
{
	p->state = state;
	p->token->data[p->j++] = c;
	p->token->type = TOKEN;
}

static void	handle_quotes(t_lexer_program *p, t_token_type quote)
{
	if (quote == CHAR_QOUTE)
		set_token(p, CHAR_QOUTE, STATE_IN_QUOTE);
	else if (quote == CHAR_DQUOTE)
		set_token(p, CHAR_DQUOTE, STATE_IN_DQUOTE);
}

static bool	handle_token_end(t_lexer_program *p)
{
	if (p->j > 0)
	{
		p->token->data[p->j] = '\0';
		p->token->next = ft_calloc(1, sizeof(t_token));
		if (!p->token->next)
			return (true);
		p->token = p->token->next;
		init_token(p->token, p->str_size - p->i);
		p->j = 0;
	}
	return (false);
}

static bool	handle_special_char(t_lexer_program *p)
{
	if (handle_token_end(p))
		return (true);
	p->token->data[0] = p->ch_type;
	p->token->data[1] = '\0';
	p->token->type = p->ch_type;
	p->token->next = ft_calloc(1, sizeof(t_token));
	if (!p->token->next)
		return (true);
	p->token = p->token->next;
	init_token(p->token, p->str_size - p->i);
	return (false);
}

bool	handle_general_state(t_lexer_program *p)
{
	bool	error;

	error = false;
	if (!p)
		return (true);
	if (p->ch_type == CHAR_QOUTE || p->ch_type == CHAR_DQUOTE)
		handle_quotes(p, p->ch_type);
	else if (p->ch_type == CHAR_ESCAPESEQUENCE)
		set_token(p, p->str[++p->i], p->state);
	else if (p->ch_type == CHAR_GENERAL)
		set_token(p, p->c, p->state);
	else if (p->ch_type == CHAR_SPACE)
		error = handle_token_end(p);
	else if (p->ch_type == CHAR_SEMICOLON || p->ch_type == CHAR_GREATER
		|| p->ch_type == CHAR_LESSER || p->ch_type == CHAR_PIPE
		|| p->ch_type == CHAR_AMPERSAND)
		error = handle_special_char(p);
	return (error);
}
