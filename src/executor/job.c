/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:49:35 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/28 17:05:34 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_job(t_node *node)
{
	if (node->type == NODE_PIPE)
		execute_pipe(node);
	else
		execute_command((t_cmd){node, false, false, 0, 0, NULL, NULL});
}
