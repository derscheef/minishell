/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:51:07 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/28 17:47:39 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "ast.h"
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_cmd
{
	t_node	*node;
	bool	is_stdin;
	bool	is_stdout;
	int		fd_read;
	int		fd_write;
	char	*redirect_in;
	char	*redirect_out;
}			t_cmd;

typedef struct s_internal_cmd
{
	size_t	ac;
	char	**av;
	bool	is_stdin;
	bool	is_stdout;
	int		fd_read;
	int		fd_write;
	char	*redirect_in;
	char	*redirect_out;
}			t_internal_cmd;

bool		execute(t_node *tree);
void		execute_job(t_node *node);
void		execute_pipe(t_node *n);
void		execute_command(t_cmd p);
void		execute_simple_command(t_cmd p);

// Actual execution
bool		execute_internal_command(t_internal_cmd *p);
bool		execute_external(t_internal_cmd *p);
bool		execute_builtin(t_internal_cmd *p);

#endif