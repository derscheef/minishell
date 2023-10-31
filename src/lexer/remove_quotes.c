/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:06:44 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/31 15:44:56 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_quotes(char *str)
{
	t_state	*state;
	char	*rv;
	char	*ptr;

	state = malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	*state = STATE_GENERAL;
	rv = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!rv)
		return (NULL);
	ptr = rv;
	while (*str)
	{
		if (*state == STATE_GENERAL)
		{
			if (*str == '\"')
				*state = STATE_IN_DQUOTE;
			else if (*str == '\'')
				*state = STATE_IN_QUOTE;
			else
				*rv++ = *str;
		}
		else if (*state == STATE_IN_DQUOTE)
		{
			if (*str == '\"')
				*state = STATE_GENERAL;
			else
				*rv++ = *str;
		}
		else if (*state == STATE_IN_QUOTE)
		{
			if (*str == '\'')
				*state = STATE_GENERAL;
			else
				*rv++ = *str;
		}
		str++;
	}
	return (ptr);
}
