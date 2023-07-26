/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/26 17:27:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	//printf("%d left: %d right: %d\n", philo->id, left, right);
	if (philo->id % 2 == 0)
	{
		// right fork first
		pthread_mutex_lock(&philo->data->forks[left]);
		message(philo->data, FORK, philo->id);
		pthread_mutex_lock(&philo->data->forks[right]);
		message(philo->data, FORK, philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[right]);
		message(philo->data, FORK, philo->id);
		pthread_mutex_lock(&philo->data->forks[left]);
		message(philo->data, FORK, philo->id);
		//left fork first
	}
}

void	put_forks_down(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	if (philo->id % 2 == 0)
	{
		// right fork first
		pthread_mutex_unlock(&philo->data->forks[left]);
		pthread_mutex_unlock(&philo->data->forks[right]);
	}
	else
	{
		//left fork first
		pthread_mutex_unlock(&philo->data->forks[right]);
		pthread_mutex_unlock(&philo->data->forks[left]);
	}
}

void	eat_meal(t_philosopher *philo)
{
	message(philo->data, EATING, philo->id);
	pthread_mutex_lock(&philo->lock);
	philo->meals += 1;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_lock(&philo->data->lock);
	philo->data->total_meals += 1;
	pthread_mutex_unlock(&philo->data->lock);
	usleep(philo->data->eat_time * 1000);
}

void	*eating(void *args)
{
	t_philosopher	*philo;
	int				meals_eaten;

	philo = (t_philosopher *)args;
	while (1)
	{
		take_forks(philo);
		eat_meal(philo);
		put_forks_down(philo);
		message(philo->data, SLEEPING, philo->id);
		usleep(philo->data->sleep_time * 1000);
		message(philo->data, THINKING, philo->id);
		pthread_mutex_lock(&philo->lock);
		meals_eaten = philo->meals;
		pthread_mutex_unlock(&philo->lock);
		if (philo->data->meals == 1 && philo->meals >= philo->data->meal_count)
		{
			break ;
		}
	}
	return (NULL);
}

void	init_threads(t_data	*data)
{
	int	index;

	index = 0;
	while (index < data->philo_count)
	{
		pthread_create(&(data->philo_threads[index]), NULL,
			&eating, &data->philos[index]);
		index++;
		usleep(1000);
	}
	index = 0;
	while (index < data->philo_count)
		pthread_join(data->philo_threads[index++], NULL);
}
