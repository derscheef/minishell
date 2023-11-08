/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:25:34 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/08 15:20:40 by ndivjak          ###   ########.fr       */
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

static char	*get_bin_path(t_env_node *env, char *command)
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

bool	execute_external(t_internal_cmd *p)
{
	pid_t	pid;
	int		stdout_fd;
	int		fd;
	char	*path;
	int		status;

	path = get_bin_path(p->env_node, p->av[0]);
	if (!path)
		path = ft_strdup(p->av[0]);
	pid = fork();
	if (pid == 0)
	{
		stdout_fd = dup(STDOUT_FILENO);
		if (p->redirect_in)
		{
			if (p->is_double)
				fd = open("/dev/stdin", O_RDONLY);
			else
				fd = open(p->redirect_in, O_RDONLY);
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		else if (p->redirect_out)
		{
			if (p->is_double)
				fd = open(p->redirect_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
			else
				fd = open(p->redirect_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		if (p->is_stdin)
			dup2(p->fd_read, STDIN_FILENO);
		if (p->is_stdout)
			dup2(p->fd_write, STDOUT_FILENO);
		if (execve(path, p->av, p->env) == -1)
		{
			dup2(stdout_fd, STDOUT_FILENO);
			switch (errno)
			{
			case EACCES:
				*p->exit_code = 126; // Command invoked cannot execute
				perror("Permission denied");
				break ;
			case ENOENT: /* No such file or directory */
			default:
				*p->exit_code = 127; // Command not found
				perror("command not found");
			}
			free(path);
			exit(*p->exit_code);
		}
	}
	free(path);
	if (pid < 0)
	{
		return (perror("fork"), true);
	}
	while (waitpid(pid, &status, 0) <= 0)
	{
	}
	*p->exit_code = WEXITSTATUS(status);
	// if (p->exit_code != 255)
	// 	exit_builtin(NULL, p);
	return (false);
}
