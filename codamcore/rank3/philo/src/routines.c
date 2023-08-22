/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routines.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 12:28:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/22 02:58:52 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Keeps track of how many meals have been eaten */
void	*supervisor(void *args)
{
	t_data		*data;

	data = (t_data *)args;
	while (is_dead(data) == false)
	{
		if (all_eaten(data) == true)
		{
			pthread_mutex_lock(&data->dead_mutex);
			data->dead = 1;
			pthread_mutex_unlock(&data->dead_mutex);
		}
		usleep(300);
	}
	return (0);
}

void	*reaper(void *args)
{
	t_philosopher	*philo;
	u_int64_t		time;

	philo = (t_philosopher *)args;
	while (is_dead(philo->data) == false)
	{
		time = get_time_ms() - philo->data->start_time;
		pthread_mutex_lock(&philo->time_check);
		if (time > philo->last_meal + philo->data->die_time)
		{
			pthread_mutex_unlock(&philo->time_check);
			message(philo->data, DEAD, philo->id);
			return (0);
		}
		pthread_mutex_unlock(&philo->time_check);
		usleep(300);
	}
	return (0);
}

/* Keep eating and sleeping until max meals have been eaten
or until someone has died */
void	*philo_routine(void *args)
{
	t_philosopher	*philo;
	pthread_t		p;

	philo = (t_philosopher *)args;
	if (pthread_create(&p, NULL, &reaper, (void *)philo) != 0)
		return (0);
	if (philo->id % 2 != 0 && philo->data->philo_count != 1)
		ft_usleep(philo->data, philo->data->eat_time);
	while (is_dead(philo->data) == false)
	{
		if (eat_meal(philo) == -1)
		{
			pthread_join(p, NULL);
			return (0);
		}
	}
	pthread_join(p, NULL);
	return (0);
}
