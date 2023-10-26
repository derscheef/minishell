/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:22:03 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/26 16:27:06 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "routine.h"
# include <curses.h>
# include <stdbool.h>
# include <stdlib.h>
# include <term.h>

void	clear_term(void);
void	print_env(t_main *main);
void	print_pwd(void);
void	execute_echo(char *input);
void	exec_export(char *input, t_main *main);

#endif
