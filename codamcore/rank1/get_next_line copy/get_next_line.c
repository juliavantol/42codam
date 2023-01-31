/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:40:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/04 01:43:57 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c helpers.c get_next_line_utils.c &&./a.out

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	size_t		check;

	if (!fd || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (search_newline(buffer) == 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check < BUFFER_SIZE)
		{
			// printf("buf: %s\n", buffer);
			// printf("stash: %s\n\n", stash);
			return (0);
		}
		// printf("buf: %s\n", buffer);
		// printf("stash: %s\n\n", stash);
		stash = ft_strjoin(stash, buffer, 0, 0);
		if (!stash)
			return (NULL);
		if (search_newline(stash) > 0)
		{
			line = extract_line(stash);
			stash = new_stash(buffer);
			return (line);
		}
	}
	return (0);
}

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
		printf("%s", s);
	}
	close(file);
	return (0);
}
