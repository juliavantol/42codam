/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 11:18:23 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/22 13:23:07 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "includes/libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
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

char	*get_cmd_path(char **paths, char	*cmd);
char	**delete_sub(const char *s);
char	**ft_split_quote(char const *s, char c);
void	error_exit(char *msg);
void	check_envp(t_pipex *pipex, char **envp);
char	**ft_split_pipex(char *s);
void	parent_free(t_pipex *pipex);

#endif
