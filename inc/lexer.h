/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:44:51 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/31 17:11:16 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "env_list.h"
# include "lexer_struct.h"
# include "main.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

typedef enum e_state
{
	STATE_IN_DQUOTE,
	STATE_IN_QUOTE,
	STATE_IN_ESCAPESEQ,
	STATE_GENERAL,
}					t_state;

typedef struct s_lexer_program
{
	t_lexer			*lexer;
	t_token			*token;
	t_env_node		*env_list;
	t_state			state;
	size_t			i;
	size_t			j;
	size_t			str_size;
	char			*str;

	char			c;
	t_token_type	ch_type;
}					t_lexer_program;

// Return status code
bool				lexer(char *str, size_t size, t_main *main);

t_token_type		get_char_type(char c);

// Token functions
bool				init_token(t_token *token, int datasize);
void				destroy_tokens(t_token *token);
void				combine_redirection_tokens(t_token *token);

// State handling
bool				handle_general_state(t_lexer_program *p);
bool				handle_quote_state(t_lexer_program *p, char quote);

// Cleanup input
char				*handle_general(char **str, char **rv, t_state *state);
char				*handle_dquote(char **str, char **rv, t_state *state);
char				*handle_quote(char **str, char **rv, t_state *state);
char				*remove_quotes(char *str);
#endif
