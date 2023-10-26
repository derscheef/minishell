/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:22:03 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/25 23:16:39 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include <curses.h>
# include <stdbool.h>
# include <stdlib.h>
# include <term.h>

void	clear_term(void);
void	print_env(void);
void	print_pwd(void);
void	execute_echo(char *input);
void	exec_export(char *input, t_main *main);

#endif
