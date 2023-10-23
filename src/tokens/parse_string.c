/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:51:12 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/23 14:05:47 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"
#include "utils.h"

static char	*skip_set(char *str, char *set)
{
	while (*str && ft_strchr(set, *str))
		str++;
	return (str);
}

static char	*skip_to_set(char *str, char *set)
{
	while (*str && !ft_strchr(set, *str))
		str++;
	return (str);
}

static size_t	get_token_count(char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		str = skip_set(str, " \t\r\v\f\n");
		if (ft_strchr("\'\"", *str))
		{
			count++;
			str = skip_to_char(str + 1, *str);
			if (!ft_strchr("\'\"", *(str + 1)))
				str = skip_to_set(str + 1, " \t\r\v\f\n");
			str++;
		}
		else if (!ft_strchr(" \t\r\v\f\n", *str))
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

static char	*remove_quotes(char *str)
{
	size_t	len;
	char	*ptr;
	char	*rv;
	char	*rv_ptr;

	ptr = str;
	len = 0;
	while (*str)
	{
		if (!(*str == '\'') && !(*str == '\"'))
			len++;
		str++;
	}
	rv = ft_calloc(len + 1, sizeof(char));
	if (!rv)
		return (NULL);
	str = ptr;
	rv_ptr = rv;
	while (*str)
	{
		if (!(*str == '\'') && !(*str == '\"'))
			*rv++ = *str;
		str++;
	}
	free(ptr);
	return (rv_ptr);
}

t_token	*parse_string_to_tokens(char *str)
{
	size_t	count;
	t_token	*tokens;
	char	*tmp;
	size_t	i;
	t_token	*ptr_token;

	count = get_token_count(str);
	tokens = ft_calloc(count + 1, sizeof(t_token));
	if (!tokens)
		return (NULL);
	ptr_token = tokens;
	i = 0;
	while (*str && i < count)
	{
		str = skip_set(str, " \t\r\v\f\n");
		if (ft_strchr("\'\"", *str))
		{
			tmp = skip_to_char(str + 1, *str);
			if (!ft_strchr("\'\"", *(tmp + 1)))
				tmp = skip_to_set(tmp + 1, " \t\r\v\f\n");
			*tokens++ = (t_token){remove_quotes(ft_substr(str, 1, tmp - str
						- 1)), argument, i++};
			str = tmp++;
		}
		else if (!ft_strchr(" \t\r\v\f\n", *str))
		{
			tmp = str;
			while (*tmp && !ft_strchr(" \t\r\v\f\n", *tmp))
			{
				if (ft_strchr("\'\"", *tmp))
					tmp = skip_to_char(tmp + 1, *tmp);
				tmp++;
			}
			*tokens++ = (t_token){remove_quotes(ft_substr(str, 0, tmp - str)),
									argument,
									i++};
			str = tmp++;
		}
	}
	return (ptr_token);
}
