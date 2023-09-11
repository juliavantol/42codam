/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:09:51 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/11 17:27:07 by juvan-to      ########   odam.nl         */
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

bool	proper_start(int argc, char **argv);
bool	valid_input(const char *input);
char	*init_prompt(const char *prompt);
void	execute(char *input, char **envp);

char	*ft_strnstr(const char *stack, const char *needle, int len);
char	*ft_substr(char const *s, int start, int len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);

void	check_command(char *input, char **envp);
void	ft_putstr_fd(char *s, int fd);

int		execute_cmd(int argc, char *argv[], char **envp);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strlen(const char *s);

bool	ft_strcmp(char *s1, char *s2);

#endif