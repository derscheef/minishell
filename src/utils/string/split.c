/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:23 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/20 14:34:46 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	str_count(char *str, char *set)
{
	int		len;
	char	*ptr;

	str = ft_strtrim(str, set);
	if (!str)
		return (0);
	ptr = str;
	len = 0;
	if (!ft_strchr(set, *str))
		len++;
	while (*str)
	{
		if (ft_strchr(set, *str))
			len++;
		str++;
	}
	free(ptr);
	return (len);
}

static int	str_len(char *str, char *set)
{
	int	len;

	len = 0;
	while (*str && !ft_strchr(set, *str))
	{
		len++;
		str++;
	}
	return (len);
}

// Split string by set of characters
char	**split_string(char *str, char *set)
{
	int		count;
	char	**tokens;
	char	**ptr;

	if (!str || !set)
		return (NULL);
	count = str_count(str, set);
	tokens = ft_calloc(count + 1, sizeof(char *));
	if (!tokens)
		return (NULL);
	ptr = tokens;
	if (!tokens)
		return (NULL);
	while (*str)
	{
		if (!ft_strchr(set, *str))
		{
			*tokens = ft_substr(str, 0, str_len(str, set));
			if (!*tokens)
				return (NULL);
			tokens++;
			str += str_len(str, set);
		}
		else
			str++;
	}
	return (ptr);
}
