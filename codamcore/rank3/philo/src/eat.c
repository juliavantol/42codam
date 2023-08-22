/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 12:17:54 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/22 23:14:14 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Locks the mutexes for the two needed forks */
int	take_forks(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	if (is_dead(philo->data) == true)
		return (-1);
	pthread_mutex_lock(&philo->data->forks[left]);
	message(philo->data, FORK, philo->id);
	if (left == right)
		return (-1);
	pthread_mutex_lock(&philo->data->forks[right]);
	message(philo->data, FORK, philo->id);
	return (1);
}

/* Unlocks the mutexes for the two forks after eating
increments the meal counters and starts sleeping */
void	put_forks_down(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	pthread_mutex_unlock(&philo->data->forks[right]);
	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_lock(&philo->lock);
	philo->meals += 1;
	if (philo->meals == philo->data->meal_count)
	{
		pthread_mutex_lock(&philo->data->lock);
		philo->data->finished_philos += 1;
		pthread_mutex_unlock(&philo->data->lock);
		philo->enough = true;
	}
	pthread_mutex_unlock(&philo->lock);
	if (is_dead(philo->data) == false)
	{
		message(philo->data, SLEEPING, philo->id);
		ft_usleep(philo->data, philo->data->sleep_time);
	}
}

/* Take the forks, start eating and put the forks down again */
int	eat_meal(t_philosopher *philo)
{
	if (take_forks(philo) == -1)
		return (-1);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal = get_time_ms() - philo->data->start_time;
	pthread_mutex_unlock(&philo->lock);
	message(philo->data, EATING, philo->id);
	ft_usleep(philo->data, philo->data->eat_time);
	put_forks_down(philo);
	if (is_dead(philo->data) == false)
		message(philo->data, THINKING, philo->id);
	return (1);
}
