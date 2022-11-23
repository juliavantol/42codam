/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:40:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/23 14:01:34 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c &&./a.out
// cc -Wall -Wextra -Werror get_next_line.c &&./a.out

void	find_break(char	*s)
{
	size_t		index;

	index = 0;
	while (s[index] != '\n')
	{
		printf("%c", s[index]);
		index++;
	}
	printf("\n");
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			bytes_read;

	if (!fd || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0)
		return (0);
	buffer[bytes_read] = '\0';
	find_break(buffer);
	return (buffer);
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
		printf("%s\n", s);
		rounds++;
	}
	close(file);
	return (0);
}
