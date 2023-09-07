/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 15:39:29 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/18 16:42:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strlen(const char *s)
{
	int	index;

	if (!s)
		return (0);
	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	return (1);
}
