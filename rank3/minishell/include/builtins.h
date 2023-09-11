/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 17:11:28 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/11 17:59:47 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_envp
{
	char			*name;
	char			*value;
	struct s_envp	*next;
}	t_envp;

void	create_envp(char **envp);
void	print_env(char **envp);
void	print_directory(void);
void	exit_shell(void);

#endif