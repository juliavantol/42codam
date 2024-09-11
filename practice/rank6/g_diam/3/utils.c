#include "g_diam.h"

int		ft_atoi(char *str)
{
	int power = 1;
	int	i = 0;
	int	num = 0;

	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	while (i >= 0)
	{
		num += (str[i] - '0') * power;
		power *= 10;
		i--;
	}
	return num;
}

int		ft_skip(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (-1);
}

int		count_dashes(char *str)
{
	int i = 0;
	int n = 0;

	while (str[i])
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	return (n);
}

void	put_num(int i)
{
	char c;

	if (i > 9)
	{
		put_num(i / 10);
		put_num(i % 10);
	}
	else
	{
		c = i + '0';
		write(1, &c, 1);
	}
}