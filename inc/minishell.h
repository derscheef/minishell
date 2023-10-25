/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:24:11 by yscheef           #+#    #+#             */
/*   Updated: 2023/10/25 16:32:53 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtins.h"
# include "env.h"
# include "executer.h"
# include "lexer.h"
# include "routine.h"
# include "signals.h"
# include "utils.h"
# include <stddef.h>

typedef struct s_main
{
	t_lexer	lexer;

	char	*input;
}			t_main;

#endif
