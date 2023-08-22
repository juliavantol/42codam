/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 16:37:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/22 18:44:02 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Parse all the needed data into the data struct */
int	parse_input(int argc, char **argv, t_data *data)
{
	data->philo_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->max_meals = false;
	data->total_meals = 0;
	data->finished_philos = 0;
	data->meal_count = 1;
	data->dead = 0;
	data->threads = 0;
	data->philos = 0;
	data->forks = 0;
	if (argc != 6 && argc != 5)
		return (-1);
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

int	allocate(t_data *data)
{
	data->threads = malloc(sizeof(pthread_t) * data->philo_count);
	data->philos = malloc(sizeof(t_philosopher) * data->philo_count);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	pthread_mutex_init(&data->dead_lock, NULL);
	if (!data->threads || !data->philos || !data->forks)
		return (-1);
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->write);
		return (-1);
	}
	return (1);
}

int	init_forks(t_data *data, int index)
{
	while (index < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[index], NULL) != 0)
		{
			pthread_mutex_destroy(&data->write);
			pthread_mutex_destroy(&data->lock);
			destroy_mutexes(data, index, 1);
			return (-1);
		}
		index++;
	}
	return (1);
}

/* Continue initialising the struct and mutexes */
int	init_struct(t_data *data, int index)
{
	if (allocate(data) == -1)
		return (-1);
	if (init_forks(data, 0) == -1)
		return (-1);
	while (index < data->philo_count)
	{
		data->philos[index].id = index + 1;
		data->philos[index].data = data;
		data->philos[index].meals = 0;
		data->philos[index].last_meal = 0;
		data->philos[index].enough = false;
		if (pthread_mutex_init(&data->philos[index].lock, NULL) != 0)
		{
			pthread_mutex_destroy(&data->write);
			pthread_mutex_destroy(&data->lock);
			destroy_mutexes(data, data->philo_count, 1);
			destroy_mutexes(data, index, 0);
			return (-1);
		}
		index++;
	}
	return (1);
}
