/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 00:40:53 by Julia         #+#    #+#                 */
/*   Updated: 2023/02/09 00:42:01 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		search_newline(char	*str);
char	*ft_calloc(size_t nelem, size_t nsize);
char	*ft_strjoin(char	*stash, char	*line, int index, int start);
char	*get_next_line(int fd);
#endif