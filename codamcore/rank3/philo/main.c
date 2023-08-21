/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/08/22 00:49:34 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leaks(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_data	data;

	//atexit(leaks);
	if (parse_input(argc, argv, &data) == -1)
		return (ft_error(&data, "Error: invalid input\n", 0));
	data.start_time = get_time_ms();
	if (init_struct(&data, 0) == -1)
		return (ft_error(&data, "Error\n", 1));
	init_threads(&data, 0);
	ft_exit(&data, 2);
	return (0);
}
