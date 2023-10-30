/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:49:35 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 10:45:00 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_job(t_executor *p)
{
	if (p->node->type == NODE_PIPE)
		execute_pipe(p);
	else
		execute_command((t_cmd){p->node, p->env, p->env_node, false, false, 0,
			0, NULL, NULL});
}
