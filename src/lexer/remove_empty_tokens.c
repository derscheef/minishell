/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_empty_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:09:08 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/10 14:16:54 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	count_tokens(t_lexer *lex)
{
	t_token	*token;
	size_t	count;

	token = lex->tokens;
	count = 0;
	while (token)
	{
		if (token->type == TOKEN)
			count++;
		token = token->next;
	}
	return (count);
}

void	remove_empty_tokens(t_lexer *lex)
{
	t_token *token;
	t_token *prev;
	t_token *next;

	token = lex->tokens;
	prev = NULL;
	while (token)
	{
		next = token->next;
		if (token->type == TOKEN && token->data[0] == '\0')
		{
			if (prev)
				prev->next = next;
			else
				lex->tokens = next;
			free(token->data);
			free(token);
		}
		else
		{
			prev = token;
		}
		token = next;
	}
	lex->ntoks = count_tokens(lex);
}