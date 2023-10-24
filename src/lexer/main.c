/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:15 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/24 12:43:02 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"
#include "utils.h"

int	lexer(char *str, size_t size, t_lexer *lexer)
{
	if (!lexer)
		return (-1);
	if (!str || !size)
		return (lexer->ntoks = 0, 0);
	lexer->tokens = malloc(sizeof(t_token));
	init_token(lexer->tokens, size);
	return (0);
}
