/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:51:12 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/20 16:48:00 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"
#include "utils.h"

static size_t	get_token_count(char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_strchr(" \t\r\v\f\n", *str))
			str++;
		if (ft_strchr("\'\"", *str))
		{
			count++;
			str = skip_to_char(str + 1, *str);
			str++;
		}
		else
		{
			count++;
			while (*str && !ft_strchr(" \t\r\v\f\n", *str))
			{
				if (ft_strchr("\'\"", *str))
					str = skip_to_char(str + 1, *str);
				str++;
			}
		}
	}
	return (count);
}

t_token	*parse_string_to_tokens(char *str)
{
	size_t	count;
	t_token	*tokens;

	count = get_token_count(str);
	tokens = ft_calloc(count + 1, sizeof(t_token *));
	if (!tokens)
		return (NULL);
	return (tokens);
}
