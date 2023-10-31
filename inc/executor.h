/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:51:07 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/31 11:31:38 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "ast.h"
# include "lexer_struct.h"
# include "main.h"
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
	int			*exit_code;
	bool		is_append;
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
	int			*exit_code;
	bool		is_append;
}				t_internal_cmd;

typedef struct s_executor
{
	t_node		*node;
	char		**env;
	t_env_node	*env_node;
	int			*exit_code;
}				t_executor;

bool			execute(t_main *p);
void			execute_job(t_executor *p);
void			execute_pipe(t_executor *p);
void			execute_command(t_cmd p);
void			execute_simple_command(t_cmd p);

// Actual execution
bool			execute_internal_command(t_internal_cmd *p);
bool			execute_external(t_internal_cmd *p);
void			execute_builtin(t_internal_cmd *p);

// fds
int				open_input_fd(t_internal_cmd *p);
int				open_output_fd(t_internal_cmd *p);
int				handle_fd(t_internal_cmd *p);
void			restore_fds(int original_stdout, int original_stdin);

#endif
