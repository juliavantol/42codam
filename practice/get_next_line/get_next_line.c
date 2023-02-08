/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 21:07:22 by Julia         #+#    #+#                 */
/*   Updated: 2023/02/08 21:32:24 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_stash(char *stash)
{
	char	*new_stash;
	int		end;
	int		index;

	end = 0;
	while (stash[end] && stash[end] != '\n')
		end++;
	if (!stash[end])
		return (free(stash), NULL);
	new_stash = ft_calloc((ft_strlen(stash) - end) + 1, sizeof(char));
	if (!new_stash)
		return (free(stash), NULL);
	index = 0;
	end++;
	while (stash[end])
		new_stash[index++] = stash[end++];
	if (ft_strlen(new_stash) == 0)
		return (free(stash), free(new_stash), NULL);
	free(stash);
	return (new_stash);
}

char	*extract_line(char *stash)
{
	char	*str;
	int		end;
	int		index;

	end = 0;
	if (!stash)
		return (NULL);
	while (stash[end] && stash[end] != '\n')
		end++;
	if (stash[end] == '\n')
		end++;
	str = ft_calloc(end + 1, sizeof(char));
	if (!str)
		return (NULL);
	index = 0;
	while (stash[index] && stash[index] != '\n')
	{
		str[index] = stash[index];
		index++;
	}
	if (stash[index] == '\n' && stash[index] != '\0')
		str[index++] = '\n';
	str[index] = '\0';
	return (str);
}

char	*fill_stash(char *stash, int fd)
{
	char	*buffer;
	int		check;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (free(stash), NULL);
	check = read(fd, buffer, BUFFER_SIZE);
	if (check == -1)
		return (free(stash), free(buffer), NULL);
	while (check > 0)
	{
		buffer[check] = '\0';
		stash = ft_strjoin(stash, buffer, 0, 0);
		if (!stash)
			return (free(buffer), NULL);
		if (find_newline(buffer) > 0)
			break ;
		check = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	stash = fill_stash(stash, fd);
	if (!stash || ft_strlen(stash) == 0)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = new_stash(stash);
	if (!stash && !line)
		return (NULL);
	return (line);
}

// int main(void)
// {
// 	printf("Hello! %d\n", BUFFER_SIZE);
// }