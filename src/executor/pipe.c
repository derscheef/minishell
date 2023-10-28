/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:02:28 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/28 16:09:35 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// fd[0] = read
// fd[1] = write
void	execute_pipe(t_node *n)
{
	int	fd[2];

	pipe(fd);
	execute_command((t_cmd){n->left, false, true, 0, fd[1], NULL, NULL});
}
