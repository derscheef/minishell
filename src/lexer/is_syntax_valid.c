/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_syntax_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:08:01 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/20 14:03:09 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "utils.h"

// str NEEDS to be start of string
static bool	is_subshell_correct(char *str, char *start)
{
	while (str != start && ft_strchr(" \t\r\v\f\n", *str))
		str--;
	if (!ft_strchr("&|", *str))
		return (false);
	return (true);
}

static int	count_subshell_chars(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			str = skip_to_char(str + 1, *str);
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

bool	is_syntax_valid(char *str)
{
	char	*ptr;

	ptr = str;
	if (count_subshell_chars(str, '(') != count_subshell_chars(str, ')'))
		return (false);
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			str = skip_to_char(str + 1, *str);
		if (*str == ')')
			if (!rev_find_in_str(ptr, str, '('))
				return (false);
		if (*str == '(')
			if (!is_subshell_correct(ptr, str))
				return (false);
		if (*str == ';' || *str == '\\')
			return (false);
		str++;
	}
	return (true);
}
