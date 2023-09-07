/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 11:18:23 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/07 16:06:37 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	int		outfile;
	int		infile;
	char	**paths;
	char	*cmd;
	char	**cmd_split;
	char	**full_envp;
}	t_pipex;

char	**ft_split_paths(char *whole_str);
char	**ft_split_args(char *s);
char	**manual_envp(void);
char	*get_cmd_path(char **paths, char	*cmd);
void	get_envp(t_pipex *pipex, char **envp);
void	free_cmd_split(t_pipex *pipex);
void	error_exit(char *msg);
int		loop_args(t_pipex *pipex, char **argv, int argc);
char	*join_str(char const *s1, char const *s2);
void	output(char *output, char *cmd, t_pipex pipex);
int		check_input(char **argv, int argc);
void	pipes(t_pipex pipex);
void	cmd_error(char *cmd);
char	*get_next_line(int fd);
int		search_newline(char *s);
bool	ft_strcmp(char *s1, char *s2);
void	here_doc(char *delimiter);
void	pipe_output(void);

#endif
