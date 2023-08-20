/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routines.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 12:28:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/18 23:09:37 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Keeps track of how many meals have been eaten */
void	*supervisor(void *args)
{
	t_data		*data;
	int			i;

	data = (t_data *)args;
	while (is_dead(data) == false && all_finished(data) == false)
	{
		i = 0;
		while (i < data->philo_count && all_finished(data) == false)
		{
			pthread_mutex_lock(&data->philos[i].lock);
			if (get_time_ms() - data->start_time
				> data->philos[i].last_meal + data->die_time)
			{
				message(data, DEAD, data->philos[i].id);
				pthread_mutex_unlock(&data->philos[i].lock);
				return (0);
			}
			pthread_mutex_unlock(&data->philos[i].lock);
			i++;
		}
		usleep(700);
	}
	return (0);
}

/* Keep eating and sleeping until max meals have been eaten
or until someone has died */
void	*philo_routine(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	if (philo->id % 2 != 0 && philo->data->philo_count != 1)
		ft_usleep(philo->data, philo->data->eat_time);
	while (is_dead(philo->data) == false && all_finished(philo->data) == false)
	{
		if (eat_meal(philo) == -1)
			return (0);
		pthread_mutex_lock(&philo->lock);
		if (philo->data->max_meals == true
			&& philo->meals == philo->data->meal_count)
		{
			pthread_mutex_unlock(&philo->lock);
			return (0);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return (0);
}
