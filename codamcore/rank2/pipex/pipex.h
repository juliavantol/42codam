/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 11:18:23 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/17 15:27:57 by juvan-to      ########   odam.nl         */
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

# define NULL_ENV                       (char *const []){ NULL }
# define DEFAULT_PATH                  (char *const []){"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/sbin"}

struct s_pipex
{
	int	outfile;
	int	infile;
};

char	*get_cmd_path(char *const envp[], char	*cmd);
char	**delete_sub(const char *s);
char	**ft_split_quote(char const *s, char c);
void	error_exit(char *msg);

#endif