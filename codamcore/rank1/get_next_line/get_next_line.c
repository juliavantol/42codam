/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:40:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/30 14:29:28 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c &&./a.out
// cc -Wall -Wextra -Werror get_next_line.c &&./a.out

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (!fd || BUFFER_SIZE < 1)
		return (NULL);
	stash = malloc(BUFFER_SIZE + 1);
	if (!stash)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (search_newline(stash) != 1)
	{
		if (read(fd, buffer, BUFFER_SIZE) == 0)
			return (0);
		stash = add_to_stash(stash, buffer);
		if (search_newline(stash) == 1)
		{
			line = extract_line(stash);
			stash = empty_stash(stash);
			return (line);
		}
	}
	return (0);
}

int	main(void)
{
	int		file;
	char	*s;
	int		rounds;

	file = open("test.txt", O_RDONLY);
	rounds = 0;
	s = "a";
	while (s)
	{
		s = get_next_line(file);
		if (s == 0)
			break ;
		printf("%s", s);
		rounds++;
	}
	close(file);
	return (0);
}