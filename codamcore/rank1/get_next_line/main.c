/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 16:43:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/13 11:41:26 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>

int	main(void)
{
	int		file;
	char	*s;
	int		index;

	s = "a";
	file = open("test.txt", O_RDONLY);
	if (!file)
		file = 1;
		index = 0;
	while (s)
	{
		s = get_next_line(file);
		if (s == 0)
			break ;
		index++;
		printf("%s", s);
		free(s);
	}
	close(file);
}
