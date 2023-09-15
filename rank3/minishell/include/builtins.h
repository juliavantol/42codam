/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:11:28 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/15 14:18:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

char	*join_three_strs(char *s1, char *s2, char *s3);

void	export(t_data *data, char *name, char *value);
void	unset(t_data *data, char *name);
void	empty_envp(t_data *data);
void	env(t_data *data);
void	exit_shell(void);
void	pwd(void);

#endif