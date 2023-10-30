/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:15 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 17:14:25 by ndivjak          ###   ########.fr       */
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
	program->lexer->ntoks = 0;
	program->state = STATE_GENERAL;
	program->str = str;
	program->str_size = size;
	return (0);
}

static int	initial_checks(char *str, size_t size, t_lexer *lexer)
{
	if (!lexer)
		return (1);
	if (!str || !size)
		return (lexer->ntoks = 0, 1);
	return (0);
}

static bool	tokenize_input(t_lexer_program *p)
{
	bool	error;

	while (p->c)
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
			p->j = 0;
		}
		p->i++;
	}
	return (false);
}

static char	*remove_quotes(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = malloc(strlen(str) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

bool	lexer(char *str, size_t size, t_main *main)
{
	t_lexer_program	p;
	char			*tmp;

	if (initial_checks(str, size, &main->lexer))
		return (true);
	if (init_lexer_program(str, size, &main->lexer, &p))
		return (1);
	if (tokenize_input(&p))
		return (1);
	p.token = main->lexer.tokens;
	while (p.token)
	{
		if (p.token->type == TOKEN)
		{
			p.token->data = replace_env_var(p.token->data, main->env_list,
					main->exit_code);
			tmp = remove_quotes(p.token->data);
			free(p.token->data);
			p.token->data = tmp;
			main->lexer.ntoks++;
		}
		p.token = p.token->next;
	}
	return (false);
}
