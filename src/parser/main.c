/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:56:07 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/25 18:09:39 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	parse(t_main *main)
{
	t_token	*token;
	t_node	*node;

	token = main->lexer.tokens;
	node = main->ast;
	if (!token || !node || main->lexer.ntoks == 0)
		return (true);
	return (false);
}
