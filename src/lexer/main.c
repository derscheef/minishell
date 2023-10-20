/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:15 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/20 16:37:16 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

t_token	*lexer(char *str)
{
	t_token	*tokens;

	if (!is_syntax_valid(str))
		return (NULL);
	tokens = parse_string_to_tokens(str);
	return (tokens);
}
