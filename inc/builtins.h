/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:22:03 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/27 11:02:32 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "routine.h"
# include <curses.h>
# include <stdbool.h>
# include <stdlib.h>
# include <term.h>

int	clear_term(void);
int	print_env(t_main *main);
int	print_pwd(void);
int	execute_echo(char *input);
int	exec_export(char *input, t_main *main);
int	exec_unset(char *input, t_main *main);
int	exec_cd(char *input);

#endif
