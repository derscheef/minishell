/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:52:09 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/31 16:49:39 by yscheef          ###   ########.fr       */
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

int	exec_cd(t_internal_cmd *cmd, char *input)
{
	char	cwd[4096];
	char	*full_path;

	if (cmd->ac > 2)
		return (0);
	full_path = NULL;
	input += 3;
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
