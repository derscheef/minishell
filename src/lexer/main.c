/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:15 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/24 14:05:49 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"
#include "utils.h"

static bool	init_lexer_program(char *str, size_t size, t_lexer *lexer,
		t_lexer_program *program)
{
	if (!program)
		return (true);
	program->lexer = lexer;
	program->lexer->tokens = calloc(1, sizeof(t_token));
	if (!program->lexer->tokens)
		return (true);
	if (init_token(program->lexer->tokens, size))
		return (true);
	program->token = program->lexer->tokens;
	program->i = 0;
	program->j = 0;
	program->ntemp = 0;
	program->state = STATE_GENERAL;
	program->str = str;
	program->str_size = size;
	return (0);
}

static int	initial_checks(char *str, size_t size, t_lexer *lexer)
{
	if (!lexer)
		return (-1);
	if (!str || !size)
		return (lexer->ntoks = 0, 0);
	return (1);
}

static bool	tokenize_input(t_lexer_program *p)
{
	bool	error;

	while (p->i < p->str_size)
	{
		p->c = p->str[p->i];
		p->ch_type = get_char_type(p->c);
		if (p->state == STATE_GENERAL)
			error = handle_general_state(p);
		else if (p->state == STATE_IN_DQUOTE)
			error = handle_quote_state(p, '\"');
		else if (p->state == STATE_IN_QUOTE)
			error = handle_quote_state(p, '\'');
		if (error)
			return (true);
		if (p->ch_type == CHAR_NULL && p->j > 0)
		{
			p->token->data[p->j] = '\0';
			p->ntemp++;
			p->j = 0;
		}
		p->i++;
	}
	return (false);
}

int	lexer(char *str, size_t size, t_lexer *lexer)
{
	t_lexer_program	program;

	if (initial_checks(str, size, lexer) < 0)
		return (initial_checks(str, size, lexer));
	if (init_lexer_program(str, size, lexer, &program))
		return (1);
	if (tokenize_input(&program))
		return (1);
	return (0);
}
