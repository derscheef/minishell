/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:14:59 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/25 16:14:32 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env_node
{
	char				*key;
	char				*value;
	struct s_env_node	*next;
}						t_env_node;

t_env_node				*init_env_list(char **env);
t_env_node				*new_env_node(char *str);
void					env_lstadd_back(t_env_node **lst, t_env_node *new);

void					print_env_list(t_env_node *env_list);

#endif
