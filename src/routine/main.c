/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheef <yscheef@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:43:50 by ndivjak           #+#    #+#             */
/*   Updated: 2023/11/13 18:43:53 by yscheef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"
#include "routine.h"
#include "utils.h"

// 1. Read input from readline
// 2. Parse input
// 3. Execute command
// 4. Print output

static void	reset_routine(t_main *main)
{
	if (main->lexer.ntoks > 0)
	{
		main->lexer.ntoks = 0;
		destroy_tokens(main->lexer.tokens);
		if (main->ast)
			destroy_ast(main->ast);
	}
	main->lexer.tokens = NULL;
	if (main->input)
		free(main->input);
	if (main->prompt)
		free(main->prompt);
}

char	*get_env_value(t_main *main, char *key)
{
	t_env_node	*env;

	env = main->env_list;
	while (env != NULL)
	{
		if (strcmp(env->key, key) == 0)
		{
			return (env->value);
		}
		env = env->next;
	}
	return (NULL);
}

char	*prompt_string(t_main *main)
{
	char	*pwd;
	char	*user;
	char	*temp;
	char	*result;
	char	*home;
	char	*relative_pwd;

	pwd = get_env_value(main, "PWD");
	user = get_env_value(main, "USER");
	home = get_env_value(main, "HOME");
	if (strncmp(pwd, home, strlen(home)) == 0)
	{
		relative_pwd = pwd + strlen(home);
		if (*relative_pwd == '/')
			relative_pwd++;
		temp = ft_strjoin(user, " @ ");
		result = ft_strjoin(temp, relative_pwd);
	}
	else
	{
		temp = ft_strjoin(user, " @ ");
		result = ft_strjoin(temp, pwd);
	}
	free(temp);
	temp = result;
	result = ft_strjoin(temp, " ❯ ");
	free(temp);
	return (result);
}

void	routine(t_main *main)
{
	while (true)
	{
		main->input = readline((main->prompt = prompt_string(main)));
		if (!main->input)
			exit_routine(main);
		add_history(main->input);
		if (!lexer(main->input, ft_strlen(main->input), main))
			remove_empty_tokens(&main->lexer);
		parse(main);
		execute(main);
		reset_routine(main);
	}
}
