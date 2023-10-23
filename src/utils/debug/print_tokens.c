/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:01:21 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/20 17:36:35 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"
#include "utils.h"

void	print_tokens(t_token *tokens)
{
	printf("%s\n", tokens->value);
	tokens++;
	while (tokens->index)
	{
		printf("%s\n", tokens->value);
		tokens++;
	}
}
