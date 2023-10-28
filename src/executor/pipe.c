/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:02:28 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/28 18:47:24 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// fd[0] = read
// fd[1] = write
void	execute_pipe(t_executor *p)
{
	int	fd[2];

	pipe(fd);
	execute_command((t_cmd){p->node->left, p->env, false, true, 0, fd[1], NULL,
		NULL});
}
