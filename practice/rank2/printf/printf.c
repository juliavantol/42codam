/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 10:37:29 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/09 11:21:15 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(int c, int *counter, int *output)
{
	(*counter)++;
	(*output) = write(1, &c, 1);
}

void	ft_putstr(char	*str, int *counter, int *output)
{
	int	index;

	index = 0;
	while (str[index])
	{
		ft_putchar(str[index], counter, output);
		index++;
	}
}

void	put_num(int num, int *counter, int *output)
{
	if (num < 0)
	{
		num *= -1;
		ft_putchar('-', counter, output);
		return (put_num(num, counter, output));
	}
	else if (num > 9)
	{
		put_num(num / 10, counter, output);
		return (put_num(num % 10, counter, output));
	}
	else
		ft_putchar(num + 48, counter, output);
}

void	put_hex(unsigned long num, int *counter, int *output)
{
	int hex;

	hex = 0;
	if (!num)
		return ;
	else
	{
		hex = num % 16;
		put_hex(num / 16, counter, output);
	}
	if (hex > 9)
		ft_putchar('a' + (hex - 10), counter, output);
	else
		put_num(hex, counter, output);
}

int	formats(const char *placeholder, va_list args, int *counter, int *output)
{
	if (*placeholder == 's')
	{
		ft_putstr(va_arg(args, char *), counter, output);
	}
	else if (*placeholder == 'c')
	{
		ft_putchar(va_arg(args, int), counter, output);
	}
	else if (*placeholder == 'd')
	{
		put_num(va_arg(args, int), counter, output);
	}
	else if (*placeholder == 'x')
	{
		put_hex(va_arg(args, unsigned long), counter, output);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	int		index;
	int		output;
	va_list	args;

	counter = 0;
	output = 0;
	index = 0;
	va_start(args, str);
	while (str[index])
	{
		if (str[index] == '%' && str[index + 1])
		{
			formats(&str[index + 1], args, &counter, &output);
			index++;
		}
		else if (str[index] != '%')
			ft_putchar(str[index], &counter, &output);
		if (output < 0)
			return (0);
		index++;
	}
	return (counter);
}

int	main(void)
{
	printf("output: %d\n", printf("hey %x\n", -23));
	printf("output: %d\n", ft_printf("hey %x\n", -23));
}
