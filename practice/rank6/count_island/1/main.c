#include "island.h"

# define LINE 1024

int	check_file(char *content)
{
	int len = 0;
	int nl = 0;
	int i = 0;

	while (content[i])
	{
		if (!(content[i] == '.' || content[i] == 'X' || content[i] == '\n'))
			return (-1);
		if (content[i] == '\n')
		{
			if (len == 0)
				len = i + 1;
			else if (i - nl != len)
				return (-1);
			nl = i;
		}
		i++;
	}
	if (content[i - 1] != '\n')
		return (-1);
	return (0);
}

char *read_file(int fd, char *content)
{
	char 	*buffer;
	char 	*temp;
	int		ret;

	buffer = ft_calloc(LINE + 1);
	ret = read(fd, buffer, LINE);
	while (ret > 0)
	{
		temp = ft_strjoin(content, buffer);
		content = temp;
		ft_bzero(buffer, LINE + 1);
		ret = read(fd, buffer, LINE);
	}
	free(buffer);
	return (content);
}

int main(int argc, char **argv)
{
	char *content = NULL;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	content = read_file(fd, content);
	if (check_file(content) == -1)
		return (1);
	close(fd);
	largest_island(content);
	count_island(content);
}

// gcc -Wall -Wextra -Werror main.c count.c largest.c utils.c -o run && ./run ex1.txt