/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:15 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/19 17:15:39 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "utils.h"

char	**lexer(char *str)
{
	char	**tokens;

	tokens = split_string(str, " \t\r\v\f\n");
	return (tokens);
}
