/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   void_pointer.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 12:30:20 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/12 00:55:54 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	to_hex2(unsigned long num, int format);
int	count_hex2(unsigned long n);

int	pointer(va_list args, int count)
{
	unsigned long	p;
	int				check;

	// max long 9223372036854775807
	// ulong max 18446744073709551615
	// min long
	p = (unsigned long)va_arg(args, void *);
	if (p == 9223372036854775807)
		count = ft_putstr("0x9223372036854775807");
	else if (p == 0)
		count = ft_putstr("0x0");
	else
	{
		count += count_hex_long(p) + 2;
		if (ft_putstr("0x") == -1 || to_hex2(p, 87) == -1)
			return (-1);
	}
	return (count);
}

int	to_hex2(unsigned long num, int format)
{
	int		check;
	int		len;
	char	*str;

	len = count_hex2(num);
	str = (char *)malloc((len + 1));
	if (!str)
		return (-1);
	str[len] = '\0';
	len--;
	while (num > 0)
	{
		if ((num % 16) < 10)
			str[len--] = (num % 16) + 48;
		else
			str[len--] = (num % 16) + format;
		num /= 16;
	}
	check = ft_putstr(str);
	free(str);
	return (check);
}

int	count_hex2(unsigned long n)
{
	int		index;

	index = 0;
	if (n == (unsigned long)-2147483648)
		return (0);
	while (n != 0)
	{		
		n = n / 16;
		index++;
	}
	return (index);
}

int	count_hex_long(unsigned long n)
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