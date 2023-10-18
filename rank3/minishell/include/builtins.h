/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:11:28 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/19 00:09:51 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include "expander.h"
# include "executor.h"
# include "libft.h"

bool	detact_newline_flag(char *str);

char	*join_three_strs(char *s1, char *s2, char *s3);

void	add_node_envp(t_envp **envp, char *key, char *value);
void	export(t_exe *executor, char *name, char *value);
void	unset(t_exe *executor, char *name);
void	echo(t_exe *executor, char **str);
void	cd(t_exe *executor, char *path);
void	empty_envp(t_exe *executor);
void	print_env(t_exe *executor);
void	env(t_exe *executor);
void	exit_shell(void);
void	pwd(void);
void	init_envp(t_exe *executor, char **envp);

int		find_envp_entry(t_exe *executor, char *name);

#endif