/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 14:16:08 by Julia         #+#    #+#                 */
/*   Updated: 2022/12/04 15:45:16 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			index;

	p = s;
	index = 0;
	while (index < n)
	{
		p[index] = '\0';
		index++;
	}
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*m;

	m = malloc(nelem * elsize);
	if (m == NULL)
		return (NULL);
	ft_bzero(m, nelem * elsize);
	return (m);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

// char	*get_next_line(int fd)
// {
// 	static char	*stash;
// 	char		*buffer;
// 	char		*line;
// 	size_t		check;

// 	if (!fd || BUFFER_SIZE < 1)
// 		return (NULL);
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	while (search_newline(buffer) == 0)
// 	{
// 		check = read(fd, buffer, BUFFER_SIZE);
// 		buffer[check] = '\0';
// 		if (check == 0)
// 			return (0);
// 		else if (check < BUFFER_SIZE)
// 		{
// 			stash = ft_strjoin(stash, buffer, 0, 0);
// 			return (extract_line(stash));
// 		}
// 		stash = ft_strjoin(stash, buffer, 0, 0);
// 		if (!stash)
// 			return (NULL);
// 		if (search_newline(stash) > 0)
// 		{
// 			line = extract_line(stash);
// 			stash = new_stash(buffer);
// 			return (line);
// 		}
// 	}
// 	return (0);
// }