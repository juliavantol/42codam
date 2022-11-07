/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 11:55:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/08 00:35:43 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_output(char	*p, va_list	args);

int	check_placeholder(const char *s, va_list args, int count)
{
	if (*s == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (*s == 'c')
	{
		count++;
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (*s == 'd' || *s == 'i')
		count += new_itoa(va_arg(args, int));
	else if (*s == '%')
	{
		ft_putstr("%");
		count++;
	}
	else if (*s == 'X' || *s == 'x' || *s == 'u')
		count = count_unsigned_int(s, args, count);
	else if (*s == 'p')
		count = pointer(args, count);
	return (count);
}

static int	loop(const char *s, va_list args, int state, int count)
{
	int	index;
	int	index2;

	index = 0;
	while (s[index])
	{
		if (s[index] == '%')
		{
			count += check_placeholder(&s[index + 1], args, count);
			index = index + 2;
		}
		else
		{
			ft_putchar(s[index]);
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
	output = loop(s, args, 0 ,0);
	if (output == -1)
		return (-1);
	va_end(args);
	return (output);
}

