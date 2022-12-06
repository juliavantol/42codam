/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 16:43:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/06 17:12:13 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>

void	leaks(void)
{
	system("leaks a.out");
}

int main(int argc, char **argv)
{
	int		file;
	char	*s;
	int		index;

	s = "a";
	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
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
	else if (argc == 1)
	{
		file = open(argv[1], O_RDONLY);
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
	return (0);
}
