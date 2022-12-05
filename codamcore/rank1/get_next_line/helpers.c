/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 14:16:08 by Julia         #+#    #+#                 */
/*   Updated: 2022/12/05 14:24:17 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int x = 0;

// char	*get_next_line(int fd)
// {
// 	static char	*stash;
// 	char		*buffer;
// 	char		*line;
// 	size_t		check;

// 	if (!fd || BUFFER_SIZE < 1)
// 		return (NULL);
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	while (search_newline(buffer) == 0)
// 	{
// 		check = read(fd, buffer, BUFFER_SIZE);
// 		buffer[check] = '\0';
// 		if (check == 0)
// 			return (0);
// 		else if (check < BUFFER_SIZE)
// 		{
// 			stash = ft_strjoin(stash, buffer, 0, 0);
// 			return (extract_line(stash));
// 		}
// 		stash = ft_strjoin(stash, buffer, 0, 0);
// 		if (!stash)
// 			return (NULL);
// 		if (search_newline(stash) > 0)
// 		{
// 			line = extract_line(stash);
// 			stash = new_stash(buffer);
// 			return (line);
// 		}
// 	}
// 	return (0);
// }