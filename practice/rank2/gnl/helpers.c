/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 13:10:15 by Julia         #+#    #+#                 */
/*   Updated: 2023/02/01 12:19:58 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char *ft_strdup(char *s)
{
	int len = 0;
	char *str;
	int index = 0;
		
	while (s[len])
		len++;
	str = (char *)malloc(sizeof(char *) * len + 1);
	if (!str)
		return (NULL);
	while (index < len)
	{
		str[index] = s[index];
		index++;
	}
	str[len] = '\0';
	return (str);
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
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
char	*ft_substr(char *s, int start, int len)
{
	int	index;
	char	*sub;

	index = 0;
	if (start >= ft_strlen(s) || ft_strlen(s) == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) || len < 0)
		sub = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else if ((start + len) > ft_strlen(s))
		sub = (char *)malloc(len * sizeof(char));
	else
		sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (index < len && s[start] != '\0')
		sub[index++] = s[start++];
	sub[index] = '\0';
	return (sub);
}

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
		ft_memdel((void**)as);
}
