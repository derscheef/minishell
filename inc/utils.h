/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:47:44 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/10 14:38:22 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../lib/libft/libft.h"
# include "lexer.h"
# include "minishell.h"
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

// AST node utils
t_node	*new_node(char *data, t_node_type type);
void	attach_node(t_node *root, t_node *left, t_node *right);
void	attach_to_last_node(t_node *root, t_node *left, t_node *right);
void	destroy_node(t_node *node);

// ENV utils
char	*replace_env_var(char *str, t_env_node *env_list, int exit_code);
char	*get_env_var(char *key, t_env_node *env_list);
void	modify_or_add_env(t_internal_cmd *main, char *key, char *value);

#endif
