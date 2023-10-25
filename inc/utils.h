/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:47:44 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/25 16:12:14 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../lib/libft/libft.h"
# include "lexer.h"
# include <stddef.h>
# include <stdio.h>

// String utils
char	**split_string(char *str, char *set);
char	*skip_to_char(char *str, char c);
char	*rev_find_in_str(char *str, char *start, char c);
char	*skip_set(char *str, char *set);
char	*skip_to_set(char *str, char *set);

// Write utils
void	ft_putstr(char *str);
void	ft_putchar(char c);

// Debug utils
void	print_tokens(t_token *tokens);

#endif
