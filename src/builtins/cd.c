/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:52:09 by yscheef           #+#    #+#             */
/*   Updated: 2023/11/10 12:47:48 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*construct_full_path(const char *current, const char *relative)
{
	char	*full_path;
	char	*temp;

	full_path = ft_strjoin(current, "/");
	temp = full_path;
	full_path = ft_strjoin(full_path, relative);
	free(temp);
	return (full_path);
}

int	exec_cd(t_internal_cmd *cmd)
{
	char	cwd[4096];
	char	*full_path;
	char	*input;

	full_path = NULL;
	if (cmd->ac < 2)
		input = NULL;
	else
		input = cmd->av[1];
	if (!input || !*input)
		input = getenv("HOME");
	else if (*input != '/')
	{
		if (getcwd(cwd, sizeof(cwd)))
		{
			full_path = construct_full_path(cwd, input);
			input = full_path;
		}
	}
	if (chdir(input) != 0)
		return (perror("cd error"), 1);
	if (full_path)
		free(full_path);
	return (0);
}
