/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:52:09 by yscheef           #+#    #+#             */
/*   Updated: 2023/11/16 22:21:42 by ndivjak          ###   ########.fr       */
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
	char	*input;
	char	*old_pwd;

	if (cmd->ac > 2)
	{
		ft_putstr_fd(" too many arguments", STDERR_FILENO);
		return (1);
	}
	if (cmd->ac < 2)
		input = getenv("HOME");
	else
		input = cmd->av[1];
	if (input && *input != '/' && getcwd(cwd, sizeof(cwd)))
		input = construct_full_path(cwd, input);
	old_pwd = get_env_var("PWD", cmd->env_node);
	if (chdir(input) != 0)
		return (perror("cd error"), 1);
	modify_or_add_env(cmd, "OLDPWD", old_pwd);
	getcwd(cwd, sizeof(cwd));
	modify_or_add_env(cmd, "PWD", cwd);
	return (0);
}
