/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <ndivjak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:44:51 by ndivjak           #+#    #+#             */
/*   Updated: 2023/10/20 13:58:51 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdbool.h>

char	**lexer(char *str);
bool	is_syntax_valid(char *str);

#endif