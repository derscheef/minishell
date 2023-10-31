/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:06:44 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/31 17:09:13 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_general(char **str, char **rv, t_state *state)
{
	if (**str == '\"')
		*state = STATE_IN_DQUOTE;
	else if (**str == '\'')
		*state = STATE_IN_QUOTE;
	else
		*(*rv)++ = **str;
	(*str)++;
	return (*rv);
}

char	*handle_dquote(char **str, char **rv, t_state *state)
{
	if (**str == '\"')
		*state = STATE_GENERAL;
	else
		*(*rv)++ = **str;
	(*str)++;
	return (*rv);
}

char	*handle_quote(char **str, char **rv, t_state *state)
{
	if (**str == '\'')
		*state = STATE_GENERAL;
	else
		*(*rv)++ = **str;
	(*str)++;
	return (*rv);
}

char	*remove_quotes(char *str)
{
	t_state	*state;
	char	*rv;
	char	*ptr;

	state = malloc(sizeof(t_state));
	rv = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	ptr = rv;
	if (!state || !rv)
		return (NULL);
	*state = STATE_GENERAL;
	while (*str)
	{
		if (*state == STATE_GENERAL)
			handle_general(&str, &rv, state);
		else if (*state == STATE_IN_DQUOTE)
			handle_dquote(&str, &rv, state);
		else if (*state == STATE_IN_QUOTE)
			handle_quote(&str, &rv, state);
	}
	free(state);
	return (ptr);
}
