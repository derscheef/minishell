/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:02:15 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 13:17:16 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	handle_quote_state(t_lexer_program *p, char quote)
{
	if (!p || !quote)
		return (true);
	p->token->data[p->j++] = p->c;
	if (p->c == quote)
		p->state = STATE_GENERAL;
	return (false);
}
