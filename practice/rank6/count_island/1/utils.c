#include "island.h"

int		ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

int		find_nl(char *str)
{
	int i = 0;

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
	int i = 0;

	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_calloc(int len)
{
	char *str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_bzero(str, len);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*output;
	int i = 0;
	int j = 0;

	if (!s1)
	{
		output = ft_calloc(ft_strlen(s2));
		while (s2[i])
		{
			output[i] = s2[i];
			i++;
		}
		return (output);
	}
	output = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2[j])
		output[i++] = s2[j++];
	return (output);
}
