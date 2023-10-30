/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:49:35 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 14:24:16 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_job(t_executor *p)
{
	if (p->node->type == NODE_PIPE)
		execute_pipe(p);
	else
		execute_command((t_cmd){p->node, p->env, p->env_node, false, false, 0,
			0, NULL, NULL, p->exit_code});
}
