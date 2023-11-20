/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/19 13:31:33 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/20 13:18:12 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "builtins.h"

void	expand_command(t_exe *executor, t_cmd *command);

char	*get_variable(t_exe *executor, char *key);

#endif
