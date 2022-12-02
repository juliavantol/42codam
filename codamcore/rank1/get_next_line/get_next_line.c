/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:40:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/02 14:20:29 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c &&./a.out

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (!fd || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (search_newline(buffer) != 1)
	{
		if (read(fd, buffer, BUFFER_SIZE) == 0)
			return (0);
		stash = ft_strjoin(stash, buffer, 0, 0);
		if (!stash)
			return (NULL);
		if (search_newline(stash) == 1)
		{
			line = extract_line(stash);
			return (line);
		}
	}
	return (stash);
}

// char	*get_next_line(int fd)
// {
// 	static char	*stash;
// 	char		*buffer;
// 	char		*line;

// 	if (!fd || BUFFER_SIZE < 1)
// 		return (NULL);
// 	stash = malloc(BUFFER_SIZE + 1);
// 	if (!stash)
// 		return (NULL);
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	while (search_newline(stash) != 1)
// 	{
// 		printf("stash: %s\n", stash);
// 		if (read(fd, buffer, BUFFER_SIZE) == 0)
// 			return (0);
// 		stash = add_to_stash(stash, buffer);
// 		if (search_newline(stash) == 1)
// 		{
// 			line = extract_line(stash);
// 			stash = add_to_stash(stash, buffer);
// 			return (line);
// 		}
// 	}
// 	return (0);
// }

int	main(void)
{
	int		file;
	char	*s;

	file = open("test.txt", O_RDONLY);
	s = "a";
	while (s)
	{
		s = get_next_line(file);
		if (s == 0)
			break ;
		printf("%s\n", s);
	}
	close(file);
	return (0);
}
