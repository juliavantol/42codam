/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:09:51 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/12 14:28:10 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include "libft.h"

typedef struct s_envp
{
	char			*variable_name;
	char			*line;
}	t_envp;

typedef struct s_data
{
	t_envp	**envp;
}	t_data;

bool	proper_start(int argc, char **argv);
bool	valid_input(const char *input);
char	*init_prompt(const char *prompt);
void	execute(char *input, char **envp);


t_envp	**dup_envp(char **envp);
void	check_command(t_data *data, char *input);

#endif