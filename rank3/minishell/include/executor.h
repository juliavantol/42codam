/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 22:54:38 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/11 14:53:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

typedef struct s_pipex
{
	int		outfile;
	int		infile;
	char	**paths;
	char	*cmd;
	char	**cmd_split;
	char	**full_envp;
}	t_pipex;

void	output(char *output, char *cmd, t_pipex pipex);
void	get_envp(t_pipex *pipex, char **envp);
void	free_cmd_split(t_pipex *pipex);
void	here_doc(char *delimiter);
void	error_exit(char *msg);
void	pipes(t_pipex pipex);
void	cmd_error(char *cmd);

char	*get_cmd_path(char **paths, char	*cmd);
char	*join_str(char const *s1, char const *s2);
char	**ft_split_paths(char *whole_str);
char	**ft_split_args(char *s);
char	**manual_envp(void);
char	*get_next_line(int fd);

int		loop_args(t_pipex *pipex, char **argv, int argc, int index);
int		check_input(char **argv, int argc);
int		search_newline(char *s);

bool	ft_strcmp(char *s1, char *s2);

#endif