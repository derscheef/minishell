/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:42:25 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/24 12:43:54 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	destroy_lexer(t_lexer *lexer)
{
	if (!lexer)
		return ;
	if (lexer->tokens)
		destroy_tokens(lexer->tokens);
}
