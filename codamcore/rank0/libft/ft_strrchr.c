/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 10:21:36 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/13 10:30:26 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*copy_string;
	int		index;
	int		str_len;

	copy_string = (char *) s;
	index = 0;
	str_len = 0;
	while (s[str_len] != '\0')
		str_len++;

	while (str_len > 0)
	{
		if (s[str_len] == c)
			return (&copy_string[str_len]);
		str_len--;
	}
	return (NULL);
}
