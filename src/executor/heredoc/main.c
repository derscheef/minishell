/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:01:08 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/30 22:33:51 by ndivjak          ###   ########.fr       */
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
	int		fd[2];
	char	*input;

	if (pipe(fd) == -1)
		return (perror("Error: couldn't create pipe in heredoc"), true);
	input = get_input(p->node->data);
	write(fd[1], input, ft_strlen(input));
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	free(input);
	return (false);
}
