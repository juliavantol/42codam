/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/06 18:42:51 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/08 23:23:19 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Convert the number with base value 10 to base value 16 */
/* keep diving by 16 and for each turn store the remainder */

int	to_hex(unsigned int num, int format)
{
	int		check;
	int		len;
	char	*str;

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
