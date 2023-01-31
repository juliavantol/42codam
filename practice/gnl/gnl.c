/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 12:50:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/01/31 13:54:05 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_header.h"
#include <fcntl.h>

void leaks(void)
{
	system("leaks a.out");
}

static int append_line(char **stash, char **line)
{
	int len = 0;
	// char *temp;
	while ((*stash)[len] != '\n' && (*stash)[len] != '\0')
		len++;
	
	*line = ft_strdup(*stash);
	return (1);
}

static int output(char **stash, char **line, int bytes_read, int fd)
{
	if (bytes_read < 0)
		return (-1);
	else if (bytes_read == 0 && stash[fd] == NULL)
		return (0);
	else
		return (append_line(&stash[fd], line));
}

int get_next_line(const int fd, char **line)
{
	static char *stash[FD_SIZE];
	char buffer[BUFFER_SIZE + 1];
	int	bytes_read;
	char *temp;
	
	if (!fd || line == NULL)
		return (-1);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (stash[fd] == NULL)
			stash[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(stash[fd], buffer);
			free(stash[fd]);
			stash[fd] = temp;
		}
		if (ft_strchr(stash[fd], '\n'))
			break;
	}
	return (output(stash, line, bytes_read, fd));
}

int	main(void)
{
	int file = open("test1.txt", O_RDONLY);
	char *temp;
	int result = 1;

	// leaks();
	temp = "a";
	while (result > 0)
	{
		result = get_next_line(file, &temp);
		printf("%s\n", temp);
	}
	return (0);
}