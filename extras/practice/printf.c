/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 17:17:14 by Julia         #+#    #+#                 */
/*   Updated: 2023/01/31 12:45:15 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void ft_print_char(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void ft_print_str(char *str, int *counter)
{
	int index = 0;
	while (str[index] != '\0')
	{
		ft_print_char(str[index], counter);
		index++;
	}
}

void ft_print_num(int num, int *counter)
{
	if (num < 0)
	{
		num *= -1;
		ft_print_char('-', counter);
		return (ft_print_num(num, counter));
	}
	else if (num >= 10)
	{
		ft_print_num(num / 10, counter);
		return (ft_print_num(num % 10, counter));
	}
	else
		ft_print_char(num + 48, counter);
	
}

void print_hex(unsigned long num, int *counter)
{
	int hex = 0;
	if (!num)
		return;
	else
	{
		hex = num % 16;
		print_hex(num / 16, counter);
	}
	if (hex > 9)
		ft_print_char('a' + (hex-10), counter);
    else
        ft_print_num(hex, counter);
}

void formats(const char *str, va_list args, int *counter)
{
	if (*str == 's')
		ft_print_str(va_arg(args, char *), counter);
	if (*str == 'd')
	{
		int num = va_arg(args, int);
		ft_print_num(num, counter);
	}
	if (*str == 'x')
	{
		unsigned long num = va_arg(args, unsigned int);
		print_hex(num, counter);
	}
}

int ft_printf(const char *str, ...)
{
	int	counter = 0;
	va_list args;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			formats(str + 1, args, &counter);
			str++;
		}
		else
			ft_print_char(*str, &counter);
		str++;
	}
	va_end(args);
	return (counter);
}

int main(void)
{
	printf("hex: %x\n", -12223482);
	ft_printf("hex: %x\n", -12223482);
}