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

static void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

static int	find_size(char *str, int i, int len)
{
	int	size;
	int	j;

	str[i] = 'Y';
	size = 1;
	j = i - len;
	if (j >= 0 && str[j] == 'X')
		size += find_size(str, j, len);
	j = i - 1;
	if (j >= 0 && str[j] == 'X')
		size += find_size(str, j, len);
	j = i + 1;
	if (j < ft_strlen(str) && str[j] == 'X')
		size += find_size(str, j, len);
	j = i + len;
	if (j < ft_strlen(str) && str[j] == 'X')
		size += find_size(str, j, len);
	return (size);
}


void	island(char *str)
{
	int	maxsize;
	int	size;
	int	len;
	int	i;

	maxsize = 0;
	len = ft_find_nl(str) + 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'X')
		{
			size = find_size(str, i, len);
			if (size > maxsize)
				maxsize = size;
		}
		i++;
	}
	ft_putnbr(maxsize);
	write(1, "\n", 1);
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
