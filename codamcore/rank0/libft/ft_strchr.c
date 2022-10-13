/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 09:54:08 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/13 10:18:30 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	int		index;
	char	*copy_string;
	int		ch;

	copy_string = (char *) str;
	ch = c;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == ch)
			return (&copy_string[index]);
		index++;
	}
	return (NULL);
}
