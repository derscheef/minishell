/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:15:32 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/19 17:30:37 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_shitstr(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	if ((unsigned int)ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	ft_strlcpy(sub, (char *)s + start, len + 1);
	return (sub);
}

char	*ft_start(char *s_pos, char *set)
{
	char	*chk;
	size_t	i;

	i = 0;
	while (*s_pos && *set)
	{
		chk = ft_strchr(s_pos, set[i]);
		if (i == ft_strlen(set) - 1)
		{
			if (chk != s_pos)
				break ;
			i = 0;
		}
		if (chk == s_pos)
		{
			s_pos++;
			i = 0;
		}
		else
			i++;
	}
	return (s_pos);
}

int	ft_end(char *s1, char *set)
{
	size_t	i;
	size_t	end;
	char	*chk;

	i = 0;
	end = 0;
	while (*s1 && *set)
	{
		chk = ft_strchr(s1, set[i]);
		if (i == ft_strlen(set) - 1)
		{
			if (chk != s1)
				break ;
			i = 0;
		}
		if (chk == s1)
		{
			s1--;
			end++;
			i = 0;
		}
		else
			i++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

// int	main(void)
// {
// 	char s[] = "fsafkiwishiki";
// 	char *result = ft_strtrim(s, "ki");
// 	printf("The result is %s\n", result);
// 	return (0);
// }