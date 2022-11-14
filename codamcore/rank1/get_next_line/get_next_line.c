/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:40:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/14 23:25:02 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42

char	*get_next_line(int fd)
{
	static int	buffer_size;
	char		*s;

#ifdef BUFFER_SIZE
	buffer_size = BUFFER_SIZE;
	printf("%d\n", buffer_size);

#else

	buffer_size = 10;
	printf("no buffer given\n");
	printf("%d\n", buffer_size);
#endif

	s = "a";
	fd--;
	return (s);
}

int	main(void)
{
	get_next_line(1);
	return (0);
}
