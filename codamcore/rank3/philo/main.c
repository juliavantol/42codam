/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/06/04 21:57:47 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	index;

	index = 1;
	if (argc != 5 && argc != 6)
	{
		put_str("Not enough arguments\n", 2);
		return (EXIT_FAILURE);
	}
	while (argv[index])
	{
		printf("%d\n", ft_atoi(argv[index]));
		index++;
	}
}
