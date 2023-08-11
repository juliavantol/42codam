/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 14:31:12 by Julia         #+#    #+#                 */
/*   Updated: 2022/11/21 13:28:00 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Check which placeholder has been given and parse it accordingly */
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

/* Print the string char by char. If the char is a %, go to check_placeholder */
static int	print_input(const char *s, va_list args, int output_len, int len)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == '%' && s[index + 1] != '\0')
		{
			len = check_placeholder(&s[index + 1], args);
			if (len == -1)
				return (-1);
			output_len += len;
			index += 2;
		}
		else if (s[index] != '%')
		{
			if (ft_putchar_len(s[index]) == -1)
				return (-1);
			output_len++;
			index++;
		}
		else
			break ;
	}
	return (output_len);
}

int	ft_printf(const char	*s, ...)
{
	int		output;
	va_list	args;

	va_start(args, s);
	output = print_input(s, args, 0, 0);
	if (output == -1)
		return (-1);
	va_end(args);
	return (output);
}
