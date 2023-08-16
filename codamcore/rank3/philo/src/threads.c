/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/16 22:49:49 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Keeps track of how many meals have been eaten */
void	*supervisor(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	while (is_dead(data) == false)
	{
		pthread_mutex_lock(&data->lock);
		if (data->max_meals == true
			&& data->total_meals == (data->philo_count * data->meal_count))
		{
			data->dead = 1;
			pthread_mutex_unlock(&data->lock);
			return (0);
		}
		pthread_mutex_unlock(&data->lock);
		usleep(500);
	}
	return (0);
}

/* Keeps checking if a philosopher should be dead */
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
			return (0);
		}
		pthread_mutex_unlock(&philo->lock);
		usleep(500);
	}
	return (0);
}

void	*philo_routine(void *args)
{
	t_philosopher	*philo;
	pthread_t		p;

	philo = (t_philosopher *)args;
	if (pthread_create(&p, NULL, &death_patrol, (void *)philo) != 0)
		return (NULL);
	if (philo->id % 2 != 0 && philo->data->philo_count != 1)
		ft_usleep(philo->data, philo->data->eat_time);
	while (is_dead(philo->data) == false)
	{
		if (eat_meal(philo) == -1)
		{
			if (pthread_join(p, NULL) != 0)
				return (NULL);
			return (0);
		}
		if (philo->data->max_meals == true
			&& philo->meals == philo->data->meal_count)
			break ;
	}
	if (pthread_join(p, NULL) != 0)
		return (NULL);
	return (0);
}

/* Creates the supervisor thread and all the philo threads */
int	init_threads(t_data	*data)
{
	int			index;
	pthread_t	p;

	index = 0;
	if (pthread_create(&p, NULL, &supervisor, (void *)data) != 0)
		return (ft_error("Error creating thread", data));
	while (index < data->philo_count)
	{
		if (pthread_create(&(data->philo_threads[index]), NULL,
				&philo_routine, (void *)&data->philos[index]) != 0)
			return (ft_error("Error creating thread", data));
		index++;
	}
	index = 0;
	while (index < data->philo_count)
	{
		if (pthread_join(data->philo_threads[index++], NULL) != 0)
			return (ft_error("Error joining thread", data));
	}
	if (pthread_join(p, NULL) != 0)
		return (ft_error("Error joining thread", data));
	return (0);
}
