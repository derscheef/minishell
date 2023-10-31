/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:07:58 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 18:12:01 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "utils.h"

void	combine_redirection_tokens(t_token *token)
{
	t_token	*tmp;
	char	*join;

	if (token->type == CHAR_GREATER)
		token->type = CHAR_DGREATER;
	else if (token->type == CHAR_LESSER)
		token->type = CHAR_DLESSER;
	tmp = token->next;
	join = ft_strjoin(token->data, tmp->data);
	free(token->data);
	token->data = join;
	token->next = tmp->next;
	free(tmp->data);
	free(tmp);
}
