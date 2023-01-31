/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 22:04:56 by Julia         #+#    #+#                 */
/*   Updated: 2023/01/23 22:42:55 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	leaks(void)
{
	system("leaks a.out");
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	int		index;

	str = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	index = 0;
	while (str1[index] != '\0')
	{
		str[index] = str1[index];
		index++;
	}
	while (*str2)
		str[index++] = *str2++;
	printf("%s\n", str);
	return (str);
}

int	main(void)
{
	ft_strjoin("This is a", " string");
	// atexit(leaks);
}
