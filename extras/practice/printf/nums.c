/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nums.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 11:31:38 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/09 11:49:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	put_char(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char	*str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		put_char(str[index]);
		index++;
	}
}

void	put_num(int num)
{
	if (num < 0)
	{
		num *= -1;
		put_char('-');
		return (put_num(num));
	}
	else if (num > 9)
	{
		put_num(num / 10);
		return (put_num(num % 10));
	}
	else
		put_char(48 + num);
}

void	put_hex(unsigned long num)
{
	int	hex;

	hex = 0;
	if (!num)
		return ;
	else
	{
		hex = num % 16;
		put_hex(num / 16);
	}
	if (hex > 9)
		put_char('a' + (hex - 10));
	else
		put_num(hex);
}

int	main(void)
{
	unsigned int	num;

	num = -2343;
	printf("%x\n", -2343);
	put_hex(num);
}