/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 16:37:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/25 22:36:28 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_input(int argc, char **argv, t_data *data)
{
	if (argc != 6 && argc != 5)
		return (-1);
	data->philo_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->meal_count = 1;
	data->finished = 0;
	data->meals = 0;
	if (argc == 6)
	{
		data->meal_count = ft_atoi(argv[5]);
		data->meals = 1;
	}
	if (!data->philo_count || !data->die_time || !data->eat_time
		|| !data->sleep_time || !data->meal_count)
		return (-1);
	if (data->philo_count < 1 || data->die_time < 1 || data->eat_time < 1
		|| data->sleep_time < 1 || data->meal_count < 1)
		return (-1);
	return (1);
}

int	init_struct(t_data *data)
{
	int	index;

	index = 0;
	data->philo_threads = malloc(sizeof(pthread_t) * data->philo_count);
	data->philos = malloc(sizeof(t_philosopher) * data->philo_count);
	pthread_mutex_init(&data->write, NULL);
	index = 0;
	while (index < data->philo_count)
	{
		data->philos[index].id = index + 1;
		data->philos[index].data = data;
		data->philos[index].meals = 0;
		pthread_mutex_init(&data->philos[index].lock, NULL);
		index++;
	}
	return (1);
}
