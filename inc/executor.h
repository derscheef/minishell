/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:51:07 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 10:43:45 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "ast.h"
# include <dirent.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_cmd
{
	t_node		*node;
	char		**env;
	t_env_node	*env_node;
	bool		is_stdin;
	bool		is_stdout;
	int			fd_read;
	int			fd_write;
	char		*redirect_in;
	char		*redirect_out;
}				t_cmd;

typedef struct s_internal_cmd
{
	size_t		ac;
	char		**av;
	char		**env;
	t_env_node	*env_node;
	bool		is_stdin;
	bool		is_stdout;
	int			fd_read;
	int			fd_write;
	char		*redirect_in;
	char		*redirect_out;
}				t_internal_cmd;

typedef struct s_executor
{
	t_node		*node;
	char		**env;
	t_env_node	*env_node;
}				t_executor;

bool			execute(t_main *p);
void			execute_job(t_executor *p);
void			execute_pipe(t_executor *p);
void			execute_command(t_cmd p);
void			execute_simple_command(t_cmd p);

// Actual execution
bool			execute_internal_command(t_internal_cmd *p);
bool			execute_external(t_internal_cmd *p);
bool			execute_builtin(t_internal_cmd *p);

#endif