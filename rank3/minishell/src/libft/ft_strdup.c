/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 14:04:33 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/15 13:13:33 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		index;

	index = 0;
	while (s[index] != '\0')
		index++;
	new = ft_malloc(index + 1);
	index = 0;
	while (s[index] != '\0')
	{
		new[index] = s[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
