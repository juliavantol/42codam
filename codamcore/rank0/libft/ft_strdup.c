/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 14:04:33 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/18 14:03:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function returns a pointer to a null-terminated byte string */
/* which is a duplicate of the string pointed to by s*/
/* Memory for the new string is obtained with malloc */

char	*ft_strdup(const char *s)
{
	char	*new;
	int		index;

	index = 0;
	while (s[index] != '\0')
		index++;
	new = malloc(index + 1);
	if (new == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		new[index] = s[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
