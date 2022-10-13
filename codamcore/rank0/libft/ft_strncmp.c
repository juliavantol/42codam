/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 10:35:36 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/13 11:25:14 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		sum;

	index = 0;
	sum = 0;
	while (index < n)
	{
		if (s1[index] != s2[index])
		{
			sum = s1[index] - s2[index];
			return (sum);
		}
		index++;
	}
	return (sum);
}
