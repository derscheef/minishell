/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:32:19 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/23 18:57:30 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"
#include "utils.h"

static char	*remove_quotes(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = malloc(strlen(str) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

static void	handle_quote_case(char **str, t_token **tokens, size_t *i)
{
	char	*tmp;

	tmp = skip_to_char((*str) + 1, **str);
	if (!ft_strchr("\'\"", *(tmp + 1)))
		tmp = skip_to_set(tmp + 1, " \t\r\v\f");
	*(*tokens)++ = (t_token){remove_quotes(ft_substr(*str, 1, tmp - *str - 1)),
		argument, (*i)++};
	*str = tmp++;
}

static void	handle_non_quote_case(char **str, t_token **tokens, size_t *i)
{
	char	*tmp;

	tmp = skip_to_next_token(*str);
	*(*tokens)++ = (t_token){remove_quotes(ft_substr(*str, 0, tmp - *str)),
		argument, (*i)++};
	*str = tmp++;
}

static size_t	get_token_count(char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		str = skip_set(str, " \t\r\v\f");
		if (ft_strchr("\'\"", *str))
		{
			count++;
			str = skip_to_char(str + 1, *str);
			if (!ft_strchr("\'\"", *(str + 1)))
				str = skip_to_set(str + 1, " \t\r\v\f");
			str++;
		}
		else if (!ft_strchr(" \t\r\v\f", *str))
		{
			count++;
			str = skip_to_next_token(str);
		}
	}
	return (count);
}

t_token	*parse_string_to_tokens(char *str)
{
	size_t	count;
	t_token	*tokens;
	t_token	*ptr_token;
	size_t	i;

	count = get_token_count(str);
	tokens = ft_calloc(count + 1, sizeof(t_token));
	if (!tokens)
		return (NULL);
	ptr_token = tokens;
	i = 0;
	while (*str && i < count)
	{
		str = skip_set(str, " \t\r\v\f");
		if (ft_strchr("\'\"", *str))
			handle_quote_case(&str, &tokens, &i);
		else if (!ft_strchr(" \t\r\v\f", *str))
			handle_non_quote_case(&str, &tokens, &i);
	}
	return (ptr_token);
}
