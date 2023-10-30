/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_to_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:55:17 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 13:02:33 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*skip_to_set(char *str, char *set)
{
	while (*str && !ft_strchr(set, *str))
		str++;
	return (str);
}
