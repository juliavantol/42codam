/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 13:58:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/23 13:59:57 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Checks if someone should die */
bool	should_die(t_data *data)
{
	bool		die;
	u_int64_t	time;
	int			i;

	i = 0;
	while (i < data->philo_count)
	{
		time = get_time_ms() - data->start_time;
		pthread_mutex_lock(&data->philos[i].lock);
		die = time > data->philos[i].last_meal + data->die_time;
		pthread_mutex_unlock(&data->philos[i].lock);
		if (die == true)
		{
			message(data, DEAD, data->philos[i].id);
			return (true);
		}
		i++;
	}
	return (false);
}

/* Checks if everyone has eaten */
bool	all_eaten(t_data *data)
{
	bool	finished;

	pthread_mutex_lock(&data->lock);
	finished = (data->max_meals && data->finished_philos == data->philo_count);
	pthread_mutex_unlock(&data->lock);
	return (finished);
}

/* Checks if someone has died or if everyone has eaten */
bool	is_dead(t_data *data)
{
	bool	dead;

	pthread_mutex_lock(&data->dead_lock);
	dead = data->dead == 1;
	pthread_mutex_unlock(&data->dead_lock);
	return (dead);
}
