/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/19 13:31:33 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/22 13:49:20 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "builtins.h"

void	expand_command(t_exe *executor, t_cmd *command);

char	*expand_string(t_exe *executor, char *input_str);
char	*ft_substr_until_end(char *s, int start);
char	*find_variable_name(char *str, int index);
char	*get_variable(t_exe *executor, char *key);

int		needs_expansion(char *str, int index);

#endif
