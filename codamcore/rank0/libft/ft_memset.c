/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:39:25 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/11 16:55:03 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*new;
	size_t	index;

	index = 0;
	new = s;
	while (index < n)
	{
		new[index] = c;
		index++;
	}
	return (new);
}

int main()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("Before: %s\n", str);
  
    // Fill 8 characters starting from str[13] with '.'
    ft_memset(str, '.', 8*sizeof(char));
  
    printf("After: %s\n", str);
  
}