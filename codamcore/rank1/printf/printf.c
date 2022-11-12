/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 11:55:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/13 00:15:21 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_output(char	*p, va_list	args);

int	check_placeholder(const char *s, va_list args, int count)
{
	if (*s == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (*s == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (*s == 'd' || *s == 'i')
		count = convert_int(args);
	else if (*s == '%')
		count = ft_putstr("%");
	else if (*s == 'X' || *s == 'x' || *s == 'u')
		count = count_unsigned_int(s, args, count);
	else if (*s == 'p')
		count = pointer(args, count);
	return (count);
}

static int	loop(const char *s, va_list args, int state, int count)
{
	int	index;
	int	res;

	index = 0;
	res = 0;
	while (s[index])
	{
		if (s[index] == '%')
		{
			res = check_placeholder(&s[index + 1], args, count);
			if (res == -1)
				return (-1);
			count += res;
			index = index + 2;
		}
		else
		{
			if (ft_putchar(s[index]) == -1)
				return (-1);
			count++;
			index++;
		}
	}
	return (count);
}

int	ft_printf(const char	*s, ...)
{
	char	*p;
	int		output;
	va_list	args;

	va_start(args, s);
	output = loop(s, args,0 ,0);
	if (output == -1)
		return (-1);
	va_end(args);
	return (output);
}
