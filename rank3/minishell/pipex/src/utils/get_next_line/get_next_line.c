/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:40:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/05 23:32:32 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_stash(char *line)
{
	char	*stash;
	size_t	index;
	size_t	end;

	end = 0;
	while (line[end] && line[end] != '\n')
		end += 1;
	if (!line[end])
		return (free(line), NULL);
	stash = ft_calloc((ft_strlen(line) - end + 1), sizeof(char));
	if (!stash)
		return (free(line), NULL);
	index = 0;
	end++;
	while (line[end])
		stash[index++] = line[end++];
	if (ft_strlen(stash) == 0)
		return (free(line), free(stash), NULL);
	free(line);
	return (stash);
}

char	*extract_line(char *stash)
{
	size_t	index;
	size_t	end;
	char	*line;

	end = 0;
	if (!stash)
		return (NULL);
	while (stash[end] && stash[end] != '\n')
		end += 1;
	if (stash[end] == '\n')
		end++;
	line = ft_calloc(1 + end, sizeof(char));
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

char	*fill_stash(int fd, char *stash)
{
	char		*buffer;
	int			check;

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

	if (BUFFER_SIZE < 1 || fd < 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	stash = fill_stash(fd, stash);
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
