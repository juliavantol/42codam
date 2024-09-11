# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define LINE_LEN 1024


int		ft_strlen(char *str);
int		ft_find_nl(char *str);
void	ft_bzero(char *str, int len);
char	*ft_calloc(int len);
char	*ft_strjoin(char *str1, char *str2);

char	*read_file(int fd, char *content);
int		check_file(char *content);
int		exit_error(void);

void	island(char *str);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_find_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_bzero(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_calloc(int len)
{
	char	*str;

	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_bzero(str, len);
	return (str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*bigboy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1)
	{
		bigboy = ft_calloc(ft_strlen(str2) + 1);
		if (!bigboy)
			return (NULL);
		while (str2[i])
		{
			bigboy[i] = str2[i];
			i++;
		}
		return (bigboy);
	}
	bigboy = ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!bigboy)
		return (NULL);
	while (str1[i])
	{
		bigboy[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		bigboy[i] = str2[j];
		i++;
		j++;
	}
	return (bigboy);
}


char	*read_file(int fd, char *content)
{
	char	*buffer;
	char	*tmp;
	int		ret;

	buffer = ft_calloc(LINE_LEN + 1);
	if (!buffer)
		return (NULL);
	ret = read(fd, buffer, LINE_LEN);
	while (ret > 0)
	{
		tmp = ft_strjoin(content, buffer);
		if (content)
			free(content);
		if (!tmp)
		{
			free(buffer);
			return (NULL);
		}
		content = tmp;
		ft_bzero(buffer, LINE_LEN + 1);
		ret = read(fd, buffer, LINE_LEN);
	}
	free(buffer);
	if (ret == -1)
	{
		if (content)
			free(content);
		return (NULL);
	}
	return (content);
}

int	check_file(char *content)
{
	int	len;
	int	nl;
	int	i;

	len = 0;
	nl = 0;
	i = 0;
	while (content[i])
	{
		if (!(content[i] == '.'|| content[i] == 'X' || content[i] == '\n'))
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

int	exit_error(void)
{
	write(1, "\n", 1);
	return (1);
}

static void	fill_island(char *str, int i, int len, char c)
{
	int	j;

	str[i] = c;
	j = i - len;
	if (j >= 0 && str[j] == 'X')
		fill_island(str, j, len, c);
	j = i - 1;
	if (j >= 0 && str[j] == 'X')
		fill_island(str, j, len, c);
	j = i + 1;
	if (j < ft_strlen(str) && str[j] == 'X')
		fill_island(str, j, len, c);
	j = i + len;
	if (j < ft_strlen(str) && str[j] == 'X')
		fill_island(str, j, len, c);
}


void	island(char *str)
{
	char	c;
	int		len;
	int		i;

	c = '0';
	len = ft_find_nl(str) + 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'X')
		{
			fill_island(str, i, len, c);
			c++;
		}
		i++;
	}
	write(1, str, ft_strlen(str));
}

int	main(int argc, char **argv)
{
	char	*content;
	int		fd;
	if (argc != 2)
		return (exit_error());
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (exit_error());
	content = NULL;
	content = read_file(fd, content);
	close(fd);
	if (!content)
		return (exit_error());
	if (check_file(content) == -1)
	{
		free(content);
		return (exit_error());
	}
	island(content);
	free(content);
	return (0);
}

//  gcc -Wall -Wextra -Werror count_mirjam.c -o run && ./run