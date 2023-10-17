/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:11:28 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/17 16:54:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include "expander.h"

bool	detact_newline_flag(char *str);

char	*join_three_strs(char *s1, char *s2, char *s3);

void	export(t_exe *executor, char *name, char *value);
void	unset(t_exe *executor, char *name);
void	echo(t_exe *executor, char **str);
void	cd(t_exe *executor, char *path);
void	empty_envp(t_exe *executor);
void	env(t_exe *executor);
void	exit_shell(void);
void	pwd(void);

int		find_envp_entry(t_exe *executor, char *name);

#endif