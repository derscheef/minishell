/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_to_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:56:42 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/23 18:56:57 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"
#include "utils.h"

char	*skip_to_next_token(char *str)
{
	while (*str && !ft_strchr(" \t\r\v\f", *str))
	{
		if (ft_strchr("\'\"", *str))
			str = skip_to_char(str + 1, *str);
		str++;
	}
	return (str);
}
