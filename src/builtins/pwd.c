/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:42:43 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/30 14:28:46 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_pwd(int fd)
{
	char	*buffer;
	size_t	size;

	buffer = NULL;
	size = 0;
	buffer = getcwd(buffer, size);
	if (buffer != NULL)
	{
		ft_putstr_fd(buffer, fd);
		ft_putchar_fd('\n', fd);
		free(buffer);
	}
	else
	{
		perror("pwd");
		return (1);
	}
	return (0);
}
