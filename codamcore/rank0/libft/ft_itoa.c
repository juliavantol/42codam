/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 11:15:13 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/25 14:59:58 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_str(int digits, char *str, int n, int index);
int		count_digits(int n);

char	*ft_itoa(int n)
{
	char	*str;
	char	*min;
	int		digits;
	int		index;

	index = 0;
	digits = count_digits(n);
	if (n == (int)-2147483648)
	{
		str = (char *)malloc(12);
		if (!str)
			return (NULL);
		min = "-2147483648\0";
		ft_strlcpy(str, min, 12);
		return (str);
	}
	else if (n == 0)
		str = malloc(2);
	else if (n < 0)
		str = (char *)malloc((digits + 2));
	else
		str = (char *)malloc((digits + 1));
	if (!str)
		return (NULL);
	return (str = fill_str(digits, str, n, index));
}

int	count_digits(int n)
{
	int		count;

	count = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*fill_str(int digits, char *str, int n, int index)
{
	char	c;
	int		d;

	d = digits - 1;
	if (n < 0)
	{
		str[index] = '-';
		n *= -1;
		index++;
		digits++;
		d++;
	}
	while (index < digits)
	{
		c = (n % 10) + 48;
		str[d--] = c;
		n = n / 10;
		index++;
	}
	str[index] = '\0';
	return (str);
}
