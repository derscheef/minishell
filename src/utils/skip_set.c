/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:54:49 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/23 18:54:50 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*skip_set(char *str, char *set)
{
	while (*str && ft_strchr(set, *str))
		str++;
	return (str);
}
