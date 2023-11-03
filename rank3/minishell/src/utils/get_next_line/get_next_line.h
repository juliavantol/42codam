/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:16:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/03 16:19:45 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*gnl_strjoin(char *stash, char *str, size_t index, size_t start);
void	*calloc_gnl(size_t nelem, size_t elsize);
int		search_newline(char *s);

#endif