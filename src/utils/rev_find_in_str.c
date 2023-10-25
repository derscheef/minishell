/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_find_in_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:31:26 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/20 13:31:31 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*rev_find_in_str(char *str, char *start, char c)
{
	while (start != str)
	{
		if (*start == c)
			return (start);
		start--;
	}
	return (NULL);
}
