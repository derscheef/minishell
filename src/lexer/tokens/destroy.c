/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:57:19 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/24 12:43:59 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	destroy_tokens(t_token *token)
{
	if (!token)
		return ;
	destroy_tokens(token->next);
	free(token->data);
	free(token);
}
