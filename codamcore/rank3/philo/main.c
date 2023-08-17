/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/08/17 14:35:44 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Clean up all the data */
void	free_all(t_data *data)
{
	int	index;

	index = 0;
	if (data->philo_threads)
		free(data->philo_threads);
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	while (index < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[index]);
		pthread_mutex_destroy(&data->philos[index].lock);
		index++;
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_input(argc, argv, &data) == -1)
		return (ft_error("Invalid input\n", &data));
	data.start_time = get_time_ms();
	if (init_struct(&data) == -1)
		return (ft_error("Malloc fail\n", &data));
	init_threads(&data);
	free_all(&data);
	return (0);
}
