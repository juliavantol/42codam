/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:40:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/15 17:53:48 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c &&./a.out
// cc -Wall -Wextra -Werror get_next_line.c &&./a.out

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 20

#endif

char	*get_next_line(int fd)
{
	char	s;

	s = 'x';
	while (read(fd, &s, 1))
	{
		printf("%c", s);
		s++;
	}
	return (0);
}

int	main(void)
{
	int		file;

	file = open("test.txt", O_RDONLY);
	get_next_line(file);
	close(file);
	return (0);
}
