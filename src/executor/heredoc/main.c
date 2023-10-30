/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:01:08 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 21:36:29 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_input(char *delim)
{
	char	*line;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	line = ft_strdup("");
	while (1)
	{
		tmp = readline("> ");
		if (!tmp)
			return (line);
		if (!ft_strcmp(tmp, delim))
		{
			free(tmp);
			return (line);
		}
		tmp2 = ft_strjoin(tmp, "\n");
		free(tmp);
		tmp3 = line;
		line = ft_strjoin(line, tmp2);
		free(tmp2);
		free(tmp3);
	}
}

bool	execute_heredoc(t_cmd *p)
{
	p->fd_write = dup(STDIN_FILENO);
	if (p->fd_write == -1)
		return (perror("Error: couldn't dup STDIN in heredoc\n"), true);
	char *input = get_input(p->node->data);
	free(p->node->data);
	p->node->data = "/dev/stdin";
	ft_putstr_fd(input, p->fd_write);
	close(p->fd_write);
	return (false);
}