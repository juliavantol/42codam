/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/06 18:42:51 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/14 16:43:10 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Count how many digits there are in the hexadecimal */
int	count_hex(unsigned long n)
{
	int		index;

	index = 0;
	while (n != 0)
	{		
		n = n / 16;
		index++;
	}
	return (index);
}

/* Convert the number to hexidecimal and return the length of the string */
int	ft_hex(unsigned long num, int format)
{
	int				check;
	unsigned long	len;
	char			*str;

	len = count_hex(num);
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
	check = ft_putstr_len(str);
	free(str);
	return (check);
}
