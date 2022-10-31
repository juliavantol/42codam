/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 11:15:13 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 13:15:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Converts int into a string */

static char	*fill_str(int digits, char *str, int n, int index);
static int	count_digits(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	if (n == (int)-2147483648)
	{
		str = (char *)malloc(12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648\0", 12);
		return (str);
	}
	digits = count_digits(n);
	if (n == 0)
		str = malloc(2);
	else if (n < 0)
		str = (char *)malloc((digits + 2));
	else
		str = (char *)malloc((digits + 1));
	if (!str)
		return (NULL);
	return (str = fill_str(digits, str, n, 0));
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
