/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:09:51 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/18 15:29:38 by juvan-to      ########   odam.nl         */
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
# include "executor.h"

bool	proper_start(int argc, char **argv);
bool	valid_input(const char *input);
char	*init_prompt(const char *prompt);

char	**new_envp(char **old_envp, int size, int skip_index);
void	ft_error(char *msg, int err_code);

#endif