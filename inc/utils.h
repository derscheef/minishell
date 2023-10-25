/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:47:44 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/25 12:40:09 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../lib/libft/libft.h"
# include <stddef.h>
# include <stdio.h>

char	**split_string(char *str, char *set);
void	ft_putstr(char *str);
void	ft_putchar(char c);

#endif
