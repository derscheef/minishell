/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:48:26 by yscheef           #+#    #+#             */
/*   Updated: 2023/11/01 15:30:21 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_echo(t_internal_cmd *p, int fd)
{
	size_t	i;
	bool	is_nl;

	is_nl = true;
	nl = 1;
	if (!p || fd < 0)
	{
		return (-1);
	}
	i = 1;
	if (i < p->ac && strcmp(p->av[i], "-n") == 0)
	{
		nl = 0;
		i++;
	}
	while (i < p->ac)
	{
		if (i == 1 && ft_strcmp(p->av[i], "-n") == 0)
		{
			is_nl = false;
			i++;
			continue ;
		}
		write(fd, p->av[i], strlen(p->av[i]));
		if (i < p->ac - 1)
			write(fd, " ", 1);
		i++;
	}
	if (is_nl)
		write(fd, "\n", 1);
	return (0);
}
