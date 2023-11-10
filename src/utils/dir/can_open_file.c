/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_open_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:00:26 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/10 17:00:53 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	can_open_file(char *filename, int mode, int *exit_code)
{
	struct stat	buff;
	int			filestat;

	filestat = stat(filename, &buff);
	// Check if file exists and the permissions
	if (filestat == -1)
	{
		if (errno == ENOENT)
		{
			*exit_code = 1;
			ft_putstr_fd(" No such file or directory\n", STDERR_FILENO);
		}
		else
		{
			*exit_code = 255;
			ft_putstr_fd(" Error getting file status.\n", STDERR_FILENO);
		}
		return (false);
	}
	// Check file permission
	if (access(filename, mode) != 0)
	{
		*exit_code = 126;
		ft_putstr_fd(" Permission denied\n", STDERR_FILENO);
		return (false);
	}
	return (true); // File exists and is accessible with given mode
}
