/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:55:07 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/24 18:37:06 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "utils.h"

bool	init_token(t_token *token, int datasize)
{
	token->data = ft_calloc(datasize + 1, sizeof(char));
	if (!token->data)
		return (true);
	token->type = CHAR_NULL;
	token->next = NULL;
	return (false);
}
