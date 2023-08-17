/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 16:37:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/17 14:32:17 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Parse all the needed data into the data struct */
int	parse_input(int argc, char **argv, t_data *data)
{
	if (argc != 6 && argc != 5)
		return (-1);
	data->philo_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->max_meals = false;
	data->total_meals = 0;
	data->meal_count = 1;
	data->dead = 0;
	if (argc == 6)
	{
		data->meal_count = ft_atoi(argv[5]);
		data->max_meals = true;
	}
	if (data->philo_count < 1 || data->die_time < 1 || data->eat_time < 1
		|| data->sleep_time < 1 || data->meal_count < 1)
		return (-1);
	return (1);
}

/* Continue initialising the struct and mutexes */
int	init_struct(t_data *data)
{
	int	index;

	data->philo_threads = malloc(sizeof(pthread_t) * data->philo_count);
	data->philos = malloc(sizeof(t_philosopher) * data->philo_count);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->philo_threads || !data->philos || !data->forks)
		return (-1);
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	index = 0;
	while (index < data->philo_count)
	{
		data->philos[index].id = index + 1;
		data->philos[index].data = data;
		data->philos[index].dead = 0;
		data->philos[index].meals = 0;
		data->philos[index].last_active = 0;
		pthread_mutex_init(&data->philos[index].lock, NULL);
		pthread_mutex_init(&data->forks[index], NULL);
		index++;
	}
	return (1);
}
