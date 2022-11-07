/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 11:55:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/07 15:02:24 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_output(char	*p, va_list	args);

int	check_placeholder(const char *s, va_list args, int count)
{
	if (*s == 's')
		count += ft_putstr(va_arg(args, char *));
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
	while (*s)
	{
		if (state == 0)
		{
			if (*s == '%')
				state = 1;
			else
			{
				ft_putchar_fd(*s, 1);
				count++;
			}
		}
		else
		{
			count = check_placeholder(s, args, count);
			state = 0;
		}
		s++;
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
	if (output == 0)
		return (0);
	va_end(args);
	return (output);
}

