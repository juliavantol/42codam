#include "g_diam.h"

int		ft_atoi(char *str)
{
	int	i = 0;
	int	power = 1;
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
	return (num);
}

int 	count_dashes(char *str)
{
	int i = 0;
	int	n = 0;

	while (str[i])
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	return (n);
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

void	put_num(int num)
{
	char c;

	if (num > 9)
	{
		put_num(num / 10);
		put_num(num % 10);
	}
	else
	{
		c = num + '0';
		write(1, &c, 1);
	}
}

int		is_new(t_node **node_list, int n)
{
	t_node *temp = *node_list;

	while (temp)
	{
		if (temp->n == n)
			return (0);
		temp = temp->next;
	}
	return (1);
}
