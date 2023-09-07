/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 12:50:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/02/01 12:19:33 by juvan-to      ########   odam.nl         */
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
	char *temp;
	while ((*stash)[len] != '\n' && (*stash)[len] != '\0')
		len++;
	if ((*stash)[len] == '\n')
	{
		*line = ft_substr(*stash, 0, len);
		temp = ft_strdup(&((*stash)[len + 1]));
		free(*stash);
		*stash = temp;
		if ((*stash)[0] == '\0')
			ft_strdel(stash);
	}
	else
	{
		*line = ft_strdup(*stash);
		ft_strdel(stash);
	}
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
	
	if (fd < 0 || line == NULL)
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
	char  *line;
  int   fd1;

  fd1 = open("test1.txt", O_RDONLY);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);


  get_next_line(fd1, &line);
  printf("%s\n", line);

  get_next_line(fd1, &line);
  printf("%s\n", line);
  close(fd1);

}