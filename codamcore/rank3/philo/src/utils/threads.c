/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/11 16:24:40 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervisor_routine(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	while (is_dead(data) == false)
	{
		pthread_mutex_lock(&data->lock);
		if (data->status == data->philo_count)
		{
			pthread_mutex_unlock(&data->lock);
			return (NULL);
		}
		pthread_mutex_unlock(&data->lock);
		usleep(500);
	}
	return (NULL);
}

void	*death_patrol(void *args)
{
	t_philosopher	*philo;
	u_int64_t		time;

	philo = (t_philosopher *)args;
	while (is_dead(philo->data) == false)
	{
		pthread_mutex_lock(&philo->lock);
		time = get_time_ms() - philo->data->start_time;
		if (time > philo->last_active + philo->data->die_time)
		{
			message(philo->data, DEAD, philo->id);
			pthread_mutex_unlock(&philo->lock);
			return ((void *)0);
		}
		if (philo->data->meals == 1 && philo->meals == philo->data->meal_count)
		{
			pthread_mutex_unlock(&philo->lock);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->lock);
		usleep(500);
	}
	return ((void *)0);
}

void	*philo_routine(void *args)
{
	t_philosopher	*philo;
	pthread_t		p;

	philo = (t_philosopher *)args;
	pthread_create(&p, NULL, &death_patrol, (void *)philo);
	if (philo->id % 2 != 0 && philo->data->philo_count != 1)
		ft_usleep(philo->data, philo->data->eat_time);
	while (is_dead(philo->data) == false)
	{
		if (eat_meal(philo) == -1)
		{
			pthread_join(p, NULL);
			return (NULL);
		}
		if (philo->data->meals == 1 && philo->meals >= philo->data->meal_count)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->status += 1;
			pthread_mutex_unlock(&philo->data->lock);
			break ;
		}
	}
	pthread_join(p, NULL);
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
	}
	index = 0;
	while (index < data->philo_count)
		pthread_join(data->philo_threads[index++], NULL);
	pthread_join(data->supervisor, NULL);
	return ;
}
