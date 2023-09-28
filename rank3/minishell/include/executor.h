/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 22:54:38 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/28 13:09:22 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <sys/types.h>
# include <sys/wait.h>
# include "minishell.h"
# include "libft.h"

typedef struct s_pipex
{
	int		outfile;
	int		infile;
	char	**paths;
	char	*cmd;
	char	**cmd_split;
	char	**full_envp;
}	t_pipex;

typedef struct s_exe
{
	char	**commands;
	int		command_count;
	int		infile;
	char	**envp;
	char	**paths;
	char	**minishell_envp;
}	t_exe;

void	run_command(t_exe *executor, char **split_cmd);
void	empty_executor(t_exe *executor);
void	start_executor(t_exe *executor);
void	temp_parser(t_exe *executor, char *input);
void	check_command(t_exe *executor, char *input);
void	init_executor(t_exe *executor, char **envp);
void	get_envp(t_pipex *pipex, char **envp);
void	free_cmd_split(t_pipex *pipex);
void	empty_array(char **arr);
void	here_doc(char *delimiter);
void	error_exit(char *msg);
void	cmd_error(char *cmd);

char	*get_cmd_path(char **paths, char	*cmd);
char	**ft_split_paths(char *whole_str);
char	**get_paths(char **envp);
char	**ft_split_args(char *s);
char	**manual_envp(void);
char	*get_next_line(int fd);

int		search_newline(char *s);

bool	ft_strcmp(char *s1, char *s2);

#endif