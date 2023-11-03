/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:22:03 by yscheef           #+#    #+#             */
/*   Updated: 2023/11/01 17:06:15 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "executor.h"
# include "routine.h"
# include <curses.h>
# include <stdbool.h>
# include <stdlib.h>
# include <term.h>

int		clear_term(void);
int		print_env(t_internal_cmd *main, int fd);
int		print_pwd(int fd);
int		execute_echo(t_internal_cmd *p, int fd);
int		exec_export(char *input, t_internal_cmd *main);
int		exec_unset(char *input, t_internal_cmd *main);
int		exec_cd(t_internal_cmd *cmd, char *input);
void	exit_builtin(char *exit_code_str, t_internal_cmd *p, t_main *main);

#endif
