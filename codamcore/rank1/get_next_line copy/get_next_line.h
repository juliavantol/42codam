/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:16:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/03 14:53:47 by Julia         ########   odam.nl         */
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
char	*add_to_stash(char *stash, char *str);
int		search_newline(char *s);
char	*extract_line(char *stash);
char	*empty_stash(char *stash);
char	*ft_strjoin(char *stash, char *str, size_t index, size_t start);
char	*new_stash(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nelem, size_t elsize);
size_t	ft_strlen(const char *s);

#endif