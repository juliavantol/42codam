/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/19 13:31:33 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/25 20:07:52 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "builtins.h"

bool	search_substring_from_index(char *stack, char *needle, int index);

void	expand_command(t_exe *executor, t_cmd *command);

char	*remove_quotes_if_necessary(char *str, char quote, int i, int j);
void	handle_quotes(char *str);
void	enclosed_in_quotes(char *str);
char	*remove_quotes(char *str, char quote, int i, int j);
char	*join_expanded_str(char *s1, char *s2, char *s3);
char	*expand_string(t_exe *executor, char *input);
char	*start_expander(t_exe *executor, t_cmd *command);
char	*find_variable_name(char *str, int index);
char	*get_variable(t_exe *executor, char *key);
char	*char_to_str(char c);

int		needs_expansion(char *str, int index);

#endif
