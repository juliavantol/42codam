/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/22 22:57:13 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	// printf("answer: %s\n", strnstr(((void *)0), "fake", 3));
	printf("answer: %s\n", strnstr("", "", 0));
	printf("mine: %s\n", ft_strnstr("", "", 0));
}

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	index;
// 	size_t	temp_index;
// 	int		needle_index;
// 	int		needle_len;

// 	needle_len = ft_strlen(needle);
// 	index = 0;
// 	needle_index = 0;
// 	if (needle[0] == '\0' || (ft_strncmp(haystack, needle, needle_len)) == 0)
// 		return ((char *)&haystack[index]);
// 	while (haystack[index] != '\0' && index < len)
// 	{
// 		needle_index = 0;
// 		temp_index = index;
// 		while (haystack[temp_index] == needle[needle_index])
// 		{
// 			temp_index++;
// 			needle_index++;
// 			if (needle_index == needle_len && (index + needle_index) < len)
// 				return ((char *)&haystack[index]);
// 		}
// 		index++;
// 	}
// 	return (NULL);
// }
