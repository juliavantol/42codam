/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:11:28 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/10/27 15:08:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include "expander.h"
# include "executor.h"
# include "libft.h"

void	add_node_envp(t_envp **envp, char *key, char *value);
void	export(t_exe *executor, char *name, char *value);
void	echo(t_exe *executor, t_cmd *command, int i);
void	init_envp(t_exe *executor, char **envp);
void	unset(t_exe *executor, char *name);
void	cd(t_exe *executor, char *path);
void	print_env(t_exe *executor);

char	*join_three_strs(char *s1, char *s2, char *s3);

bool	detact_newline_flag(char *str);

#endif