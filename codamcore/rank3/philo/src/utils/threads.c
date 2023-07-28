/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/28 23:17:56 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervisor_routine(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	while (1)
	{
		pthread_mutex_lock(&data->lock);
		if (data->status == data->philo_count)
		{
			pthread_mutex_unlock(&data->lock);
			break ;
		}
		pthread_mutex_unlock(&data->lock);
		usleep(1000);
	}
	return (NULL);
}

void	*death_patrol(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	while (1)
	{
		
	}
	return (NULL);
}

void	*philo_routine(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	while (1)
	{
		take_forks(philo);
		eat_meal(philo);
		put_forks_down(philo);
		message(philo->data, SLEEPING, philo->id);
		usleep(philo->data->sleep_time * 1000);
		message(philo->data, THINKING, philo->id);
		if (philo->data->meals == 1 && philo->meals >= philo->data->meal_count)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->status += 1;
			pthread_mutex_unlock(&philo->data->lock);
			break ;
		}
	}
	return (NULL);
}

void	init_threads(t_data	*data)
{
	int			index;

	index = 0;
	pthread_create(&data->supervisor, NULL, &supervisor_routine, (void *)data);
	while (index < data->philo_count)
	{
		pthread_create(&(data->philo_threads[index]), NULL,
			&philo_routine, (void *)&data->philos[index]);
		index++;
		usleep(1000);
	}
	index = 0;
	while (index < data->philo_count)
		pthread_join(data->philo_threads[index++], NULL);
	pthread_join(data->supervisor, NULL);
	printf("end status: %d\n", data->status);
}
