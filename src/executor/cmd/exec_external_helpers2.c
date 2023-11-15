/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external_helpers2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:32:56 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/15 03:45:37 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_bin(t_internal_cmd *p, char *path, int stdout_fd)
{
	if (execve(path, p->av, p->env) == -1)
	{
		dup2(stdout_fd, STDOUT_FILENO);
		if (errno == EACCES)
		{
			*p->exit_code = 126;
			ft_putstr_fd(" Permission denied\n", STDERR_FILENO);
		}
		else if (errno == ENOENT)
		{
			*p->exit_code = 127;
			ft_putstr_fd(" No such file or directory\n", STDERR_FILENO);
		}
		else
		{
			*p->exit_code = 127;
			ft_putstr_fd(" command not found\n", STDERR_FILENO);
		}
	}
	else
		*p->exit_code = 0;
}

void	wait_for_child(t_internal_cmd *p, pid_t pid, int *status)
{
	while (waitpid(pid, status, 0) <= 0)
		;
	*p->exit_code = WEXITSTATUS(*status);
	handle_signals();
}

void	set_to_ignore(void)
{
	struct sigaction	sa_default;

	sa_default.sa_handler = SIG_IGN;
	sigemptyset(&sa_default.sa_mask);
	sa_default.sa_flags = 0;
	sigaction(SIGINT, &sa_default, NULL);
	sigaction(SIGQUIT, &sa_default, NULL);
}
