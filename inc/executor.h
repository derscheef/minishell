/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:51:07 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/08 18:44:01 by ndivjak          ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>

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
	bool		is_double;
	t_main		*main;
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
	bool		is_double;
	t_main		*main;
}				t_internal_cmd;

typedef struct s_executor
{
	t_node		*node;
	char		**env;
	t_env_node	*env_node;
	int			*exit_code;
	t_main		*main;
}				t_executor;

bool			execute(t_main *p);
void			execute_job(t_executor *p);
void			execute_pipe(t_executor *p);
void			execute_command(t_cmd p);
void			execute_simple_command(t_cmd p);
bool			execute_heredoc(t_cmd *p);

// Actual execution
bool			check_command_type(t_internal_cmd *p);
bool			execute_external(t_internal_cmd *p);
void			execute_builtin(t_internal_cmd *p);

// fds
int				open_input_fd(t_internal_cmd *p);
int				open_output_fd(t_internal_cmd *p);
int				handle_fd(t_internal_cmd *p);
void			restore_fds(int original_stdout, int original_stdin);

// External exec helpers
char			*get_path(t_internal_cmd *p);
char			*get_bin_path(t_env_node *env, char *command);
void			handle_redirect_in(t_internal_cmd *p, int *fd);
void			handle_redirect_out(t_internal_cmd *p, int *fd);
void			handle_stdin_stdout(t_internal_cmd *p);
void			execute_bin(t_internal_cmd *p, char *path, int stdout_fd);
void			wait_for_child(t_internal_cmd *p, pid_t pid, int *status);
void			set_to_ignore(void);

#endif
