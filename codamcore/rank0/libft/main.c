/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/21 09:15:32 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(void)
{
	char	**tabstr;
	size_t	i = 0;

	if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
		ft_print_result("NULL");
	else
	{
		while (tabstr[i] != NULL)
		{
			ft_print_result(tabstr[i]);
			write(1, "\n", 1);
			i++;
		}
		printf("%s\n", tabstr[i]);
	}
}
