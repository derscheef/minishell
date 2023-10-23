/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:46:40 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/23 18:57:15 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include <stddef.h>

typedef enum e_token_type
{
	command,
	argument,
	redirect,
	semicolon
}					t_token_type;
typedef struct s_token
{
	char			*value;
	t_token_type	type;
	size_t			index;
}					t_token;

t_token				*parse_string_to_tokens(char *str);

// Utility
char				*skip_to_next_token(char *str);

#endif
