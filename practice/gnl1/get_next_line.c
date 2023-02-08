/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 00:40:36 by Julia         #+#    #+#                 */
/*   Updated: 2023/02/09 00:54:54 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_stash(char	*stash)
{
	char	*new_stash;
	int		index;
	int		end;

	end = 0;
	while (stash[end] && stash[end] != '\n')
		end++;
	if (!stash[end])
		return (free(stash), NULL);
	new_stash = ft_calloc(ft_strlen(stash) - end + 1, sizeof(char));
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

char	*extract_line(char	*stash)
{
	char	*line;
	int		index;
	int		end;

	if (!stash)
		return (NULL);
	end = 0;
	while (stash[end] && stash[end] != '\n')
		end++;
	if (stash[end] == '\n')
		end++;
	line = ft_calloc(end + 1, sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	while (stash[index] && stash[index] != '\n')
	{
		line[index] = stash[index];
		index++;
	}
	if (stash[index] == '\n' && stash[index] != '\0')
		line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*fill_stash(char	*stash,	int fd)
{
	char	*buffer;
	int		check;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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
		if (search_newline(buffer) > 0)
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

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE >= 2147483647)
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
