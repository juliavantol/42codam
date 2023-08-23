/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routines.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 12:28:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/23 17:06:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Keeps track of how many meals have been eaten */
void	*supervisor(void *args)
{
	t_data		*data;

	data = (t_data *)args;
	while (is_dead(data) == false && should_die(data) == false)
	{
		if (all_eaten(data) == true)
		{
			pthread_mutex_lock(&data->dead_lock);
			data->dead = 1;
			pthread_mutex_unlock(&data->dead_lock);
		}
		usleep(1000);
	}
	return (0);
}

void	*reaper(void *args)
{
	t_philosopher	*philo;
	u_int64_t		time;
	bool			die;

	philo = (t_philosopher *)args;
	ft_usleep(philo->data, philo->data->die_time);
	time = get_time_ms() - philo->data->start_time;
	pthread_mutex_lock(&philo->lock);
	die = time > philo->last_meal + philo->data->die_time;
	pthread_mutex_unlock(&philo->lock);
	if (die == true)
		message(philo->data, DEAD, philo->id);
	return (0);
}

/* Keep eating and sleeping until max meals have been eaten
or until someone has died */
void	*philo_routine(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	if (philo->id % 2 == 0 && philo->data->philo_count != 1)
		ft_usleep(philo->data, philo->data->eat_time);
	while (is_dead(philo->data) == false)
	{
		if (eat_meal(philo) == -1)
		{
			return (0);
		}
	}
	return (0);
}
