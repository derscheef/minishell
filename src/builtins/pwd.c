/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:42:43 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/25 12:45:43 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_pwd(void)
{
	char	*buffer;
	size_t	size;

	buffer = NULL;
	size = 0;
	buffer = getcwd(buffer, size);
	if (buffer != NULL)
	{
		printf("%s\n", buffer);
		free(buffer);
	}
	else
	{
		perror("pwd");
	}
}
