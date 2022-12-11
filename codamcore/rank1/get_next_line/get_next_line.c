/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:40:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/12 00:56:00 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_stash(char *line)
{
	char	*stash;
	size_t	j;
	size_t	end;

	end = 0;
	while (line[end] && line[end] != '\n')
		end += 1;
	if (!line[end])
	{
		free(line);
		return (NULL);
	}
	stash = ft_calloc((ft_strlen(line) - end + 1), sizeof(char));
	if (!stash)
	{
		free(line);
		return (NULL);
	}
	end++;
	j = 0;
	while (line[end])
		stash[j++] = line[end++];
	free(line);
	return (stash);
}

char	*extract_line(char *stash)
{
	size_t	index;
	size_t	end;
	char	*line;

	index = 0;
	end = 0;
	if (!stash[0])
		return (NULL);
	while (stash[end] && stash[end] != '\n')
		end += 1;
	line = ft_calloc(end + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (index < ft_strlen(stash))
	{
		line[index] = stash[index];
		if (stash[index] == '\n')
			break ;
		index++;
	}
	if (stash[index] != '\n' && stash[index] != '\0')
		line[index] = '\n';
	return (line);
}

char	*fill_stash(int fd, char *stash)
{
	char		*buffer;
	int			check;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(stash), NULL);
	check = read(fd, buffer, BUFFER_SIZE);
	while (check > 0)
	{
		if (check == -1)
			return (free(buffer), NULL);
		buffer[check] = '\0';
		stash = ft_strjoin(stash, buffer, 0, 0);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
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

	if (!fd || BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash || ft_strlen(stash) == 0)
		return (NULL);
	line = extract_line(stash);
	stash = new_stash(stash);
	if (!stash && !line)
		return (NULL);
	return (line);
}
