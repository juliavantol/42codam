/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 16:37:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/22 14:55:56 by juvan-to      ########   odam.nl         */
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
		data->all_philos[i].start_action = 0;
		data->all_philos[i].end_action = 0;
		if (pthread_mutex_init(&data->all_philos[i].lock, NULL) != 0)
			ft_printf("error\n");
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

void	parse(int argc, char **argv, t_data *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->finished = 0;
	data->status = 1;
	if (argc == 6)
	{
		data->number_of_times_to_eat = 1;
		data->max_meals = ft_atoi(argv[5]);
	}
	else
	{
		data->number_of_times_to_eat = 0;
		data->max_meals = 0;
	}
	data->start_time = get_time_ms();
	data->timestamp_ms = (time.tv_sec) * 1000 + (time.tv_usec) / 1000 ;
	data->threads = malloc(sizeof(pthread_t) * data->number_of_philosophers);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	data->philo_locks = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	data->all_philos = malloc(sizeof(t_philosopher) * data->number_of_philosophers);
	init_forks(data, 0);
}
