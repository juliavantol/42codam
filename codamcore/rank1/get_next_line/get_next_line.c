/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:40:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/05 14:45:06 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c helpers.c get_next_line_utils.c &&./a.out
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=55 get_next_line.c helpers.c get_next_line_utils.c &&./a.out
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=5000 get_next_line.c helpers.c get_next_line_utils.c &&./a.out

static char	*empty_stash(char	*stash)
{
	size_t	index;

	index = 0;
	while (stash[index])
		stash[index++] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	int			check;
	size_t		check2;

	if (!fd || BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	check = 1;
	if (search_newline(stash) > 0)
	{
		line = extract_line(stash);
		stash = new_stash(stash);
		return (line);
	}
	check2 = 1;
	if (stash)
		check2 = ft_strlen(stash);
	while (check > 0 && check2 != 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			return (free(buffer), NULL);
		if (check == 0)
			break ;
		buffer[check] = '\0';
		stash = ft_strjoin(stash, buffer, 0, 0);
		if (!stash)
			return (NULL);
	}
	if (search_newline(stash) > 0)
	{
		line = extract_line(stash);
		stash = new_stash(stash);
		return (line);
	}
	else if (search_newline(stash) == 0 && ft_strlen(stash) > 0)
	{
		line = extract_line(stash);
		stash = empty_stash(stash);
		return (line);
	}
	return (0);
}

// int	main(void)
// {
// 	int		file;
// 	char	*s;
// 	int		index;

// 	file = open("test.txt", O_RDONLY);
// 	s = "a";
// 	index = 0;
// 	while (s)
// 	{
// 		s = get_next_line(file);
// 		printf("%s", s);
// 		if (s == 0)
// 			break ;
// 		index++;
// 	}
// 	close(file);
// 	return (0);
// }
