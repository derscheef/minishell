/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:31:00 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/08 18:36:54 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_str_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*check_path(char *path, char *command)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*rv;
	char			*tmp;

	rv = NULL;
	dir = opendir(path);
	if (!dir)
		return (NULL);
	entry = readdir(dir);
	while (entry)
	{
		if (!ft_strcmp(entry->d_name, command))
		{
			tmp = ft_strjoin(path, "/");
			rv = ft_strjoin(tmp, command);
			free(tmp);
			break ;
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (rv);
}

char	*get_bin_path(t_env_node *env, char *command)
{
	char	*path_var;
	char	**paths;
	char	*found_path;
	int		i;

	i = -1;
	path_var = NULL;
	while (env)
	{
		if (ft_strncmp(env->key, "PATH", 5) == 0)
		{
			path_var = env->value;
			break ;
		}
		env = env->next;
	}
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	if (!paths)
		return (NULL);
	found_path = NULL;
	while (paths[++i] && !found_path)
		found_path = check_path(paths[i], command);
	return (free_str_arr(paths), found_path);
}
