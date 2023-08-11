/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/08/11 17:02:54 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	leaks(void)
{
	system("leaks philo");
}

void	free_all(t_data *data)
{
	free(data->philo_threads);
	free(data->philos);
	free(data->forks);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_input(argc, argv, &data) == -1)
	{
		printf("Invalid input\n");
		exit(1);
	}
	data.start_time = get_time_ms();
	init_struct(&data);
	init_threads(&data);
	free_all(&data);
}
