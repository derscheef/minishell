/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:22:03 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/30 15:30:35 by yscheef          ###   ########.fr       */
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

int	clear_term(void);
int	print_env(t_internal_cmd *main, int fd);
int	print_pwd(int fd);
int	execute_echo(char *input, int fd);
int	exec_export(char *input, t_internal_cmd *main);
int	exec_unset(char *input, t_internal_cmd *main);
int	exec_cd(char *input);

#endif
