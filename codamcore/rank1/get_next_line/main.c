/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 16:43:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/12 00:18:22 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c &&./a.out
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=55 get_next_line.c get_next_line_utils.c main.c &&./a.out
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=5000 get_next_line.c get_next_line_utils.c main.c &&./a.out

void	leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	int		file;
	char	*s;
	int		index;

	s = "a";
	file = open("1char.txt", O_RDONLY);
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
	// leaks();
	close(file);
}

// int main(int argc, char **argv)
// {
// 	int		file;
// 	char	*s;
// 	int		index;

// 	s = "a";
// 	if (argc == 2)
// 	{
// 		file = open(argv[1], O_RDONLY);
// 		if (!file)
// 			file = 1;
// 		index = 0;
// 		while (s)
// 		{
// 			s = get_next_line(file);
// 			if (s == 0)
// 				break ;
// 			index++;
// 			printf("%s", s);
// 			free(s);
// 		}
// 		close(file);
// 	}
// 	else if (argc == 1)
// 	{
// 		file = open("test.txt", O_RDONLY);
// 		if (!file)
// 			file = 1;
// 		index = 0;
// 		while (s)
// 		{
// 			s = get_next_line(file);
// 			if (s == 0)
// 				break ;
// 			index++;
// 			printf("%s", s);
// 			free(s);
// 		}
// 		// leaks();
// 		close(file);
// 	}
// 	return (0);
// }
