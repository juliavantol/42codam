/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 14:31:12 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/15 11:59:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_placeholder(const char *s, va_list args)
{
	if (*s == 's')
		return (ft_putstr_len(va_arg(args, char *)));
	else if (*s == 'c')
		return (ft_putchar_len(va_arg(args, int)));
	else if (*s == 'd' || *s == 'i')
		return (ft_itoa_len(va_arg(args, int)));
	else if (*s == 'u')
		return (parse_decimal(args));
	else if (*s == '%')
		return (ft_putstr_len("%"));
	else if (*s == 'X' || *s == 'x')
		return (parse_hex(s, args));
	else if (*s == 'p')
		return (parse_pointer(args));
	return (0);
}

static int	print_input(const char *s, va_list args, int count)
{
	int	index;
	int	res;

	index = 0;
	res = 0;
	while (s[index])
	{
		if (s[index] == '%')
		{
			res = check_placeholder(&s[index + 1], args);
			if (res == -1)
				return (-1);
			count += res;
			index = index + 2;
		}
		else
		{
			if (ft_putchar_len(s[index]) == -1)
				return (-1);
			count++;
			index++;
		}
	}
	return (count);
}

int	ft_printf(const char	*s, ...)
{
	int		output;
	va_list	args;

	va_start(args, s);
	output = print_input(s, args, 0);
	if (output == -1)
		return (-1);
	va_end(args);
	return (output);
}
