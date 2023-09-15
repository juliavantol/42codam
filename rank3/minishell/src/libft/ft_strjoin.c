/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 07:25:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/15 16:45:04 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	str_len;
	int		i;
	int		second;

	str_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)ft_malloc((str_len + 1) * sizeof(char));
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	second = i;
	i = 0;
	while (s2[i] != '\0')
		new_str[second++] = s2[i++];
	new_str[second] = '\0';
	return (new_str);
}

char	*ft_strjoin_multiple(char **strs)
{
	char	*output;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (strs[i])
		count += ft_strlen(strs[i++]);
	output = ft_malloc(count + 1 * sizeof(char));
	i = 0;
	count = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
			output[count++] = strs[i][j++];
		i++;
	}
	output[count] = '\0';
	return (output);
}
