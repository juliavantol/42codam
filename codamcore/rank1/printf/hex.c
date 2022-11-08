/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/06 18:42:51 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/08 23:17:13 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Convert the number with base value 10 to base value 16 */
/* keep diving by 16 and for each turn store the remainder */

static int	print_reverse(char *s, int count);

void	to_hex(unsigned int num, int format)
{
	int		remainder;

	if (num == 0)
		return ;
	if (num != 0)
		to_hex(num / 16, format);
	remainder = num % 16;
	if (remainder < 10)
		ft_putchar((remainder + 48));
	else
		ft_putchar((remainder + format));
}

int	to_hex2(unsigned int num, int format)
{
	int		remainder;
	int		check;
	int		index;
	int		len;
	char	*str;

	check = 0;
	if (num == 0)
		return (check);
	len = count_hex(num);
	str = (char *)malloc((len + 1));
	if (!str)
		return (-1);
	index = 0;
	str[len] = '\0';
	len--;
	while (num > 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			str[len] = remainder + 48;
		else
			str[len] = remainder + format;
		num /= 16;
		len--;
	}
	check = ft_putstr(str);
	free(str);
	return (check);
}

int	count_hex(unsigned int n)
{
	int		index;

	index = 0;
	if (n == (unsigned int)-2147483648)
		return (0);
	while (n != 0)
	{		
		n = n / 16;
		index++;
	}
	return (index);
}

static int	print_reverse(char *s, int count)
{
	int	check;

	check = 0;
	while (count >= 0)
	{
		check = ft_putchar(s[count]);
		if (check == -1)
			return (-1);
		count--;
	}
	return (0);
}
