#include "g_diam.h"

void	put_num(int n)
{
	char c;

	if (n > 9)
	{
		put_num(n / 10);
		put_num(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

int		ft_atoi(char *str)
{
	int i = 0;
	int num = 0;
	int	power = 1;

	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	while (i >= 0)
	{
		num += (str[i] - '0') * power;
		power *= 10;
		i--;
	}
	return (num);
}

int		ft_skip(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return -1;
}

int		count_dashes(char *str)
{

}
