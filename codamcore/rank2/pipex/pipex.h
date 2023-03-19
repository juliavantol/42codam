/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 11:18:23 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/19 15:55:09 by juvan-to      ########   odam.nl         */
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
	char	*all_paths[];
} t_pipex;

char	*get_cmd_path(char *const envp[], char	*cmd);
char	**delete_sub(const char *s);
char	**ft_split_quote(char const *s, char c);
void	error_exit(char *msg);
char 	**get_paths(void);

#endif