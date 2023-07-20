/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 16:37:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/20 14:33:51 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_data *data, int i)
{
	int left;
	int right;

	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	while (i < data->number_of_philosophers)
	{
		data->all_philos[i].id = i + 1;
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			ft_printf("error\n");
		if (pthread_mutex_init(&data->philo_locks[i], NULL) != 0)
			ft_printf("error\n");
		data->all_philos[i].data = data;
		data->all_philos[i].meals = 0;
		data->all_philos[i].dead = 0;
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		left = i;
		right = (i % data->number_of_philosophers) - 1;
		data->all_philos[i].left = &data->forks[left];
		if (right > -1)
			data->all_philos[i].right = &data->forks[right];
		i++;
	}
}

void	parse(int argc, char **argv, t_data *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		philo->number_of_times_to_eat = 1;
		philo->max_meals = ft_atoi(argv[5]);
	}
	else
	{
		philo->number_of_times_to_eat = 0;
		philo->max_meals = 0;
	}
	philo->timestamp_ms = (time.tv_sec) * 1000 + (time.tv_usec) / 1000 ;
	philo->threads = malloc(sizeof(pthread_t) * philo->number_of_philosophers);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->number_of_philosophers);
	philo->philo_locks = malloc(sizeof(pthread_mutex_t) * philo->number_of_philosophers);
	philo->all_philos = malloc(sizeof(t_philosopher) * philo->number_of_philosophers);
	init_forks(philo, 0);
}
