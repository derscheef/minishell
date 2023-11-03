/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:14:59 by yscheef           #+#    #+#             */
/*   Updated: 2023/11/01 16:49:01 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "env_list.h"
# include "main.h"

t_env_node	*init_env_list(char **env);
t_env_node	*new_env_node(char *str);
void		env_lstadd_back(t_env_node **lst, t_env_node *new);
void		env_init(t_main *main, char **env);
void		print_env_list(t_env_node *env_list);
void		destroy_env_list(t_env_node *head);

#endif
