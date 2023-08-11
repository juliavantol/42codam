/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 12:17:54 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/08 13:36:10 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	if (philo->data->dead != 0)
		return ;
	pthread_mutex_lock(&philo->data->forks[left]);
	message(philo->data, FORK, philo->id);
	pthread_mutex_lock(&philo->data->forks[right]);
	message(philo->data, FORK, philo->id);
}

void	put_forks_down(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_unlock(&philo->data->forks[right]);
	if (philo->data->dead == 0)
	{
		message(philo->data, SLEEPING, philo->id);
		ft_usleep(philo->data, philo->data->sleep_time);
	}
}

void	eat_meal(t_philosopher *philo)
{
	take_forks(philo);
	message(philo->data, EATING, philo->id);
	pthread_mutex_lock(&philo->lock);
	philo->last_active = get_time_ms() - philo->data->start_time;
	pthread_mutex_unlock(&philo->lock);
	ft_usleep(philo->data, philo->data->eat_time);
	put_forks_down(philo);
	pthread_mutex_lock(&philo->lock);
	philo->meals += 1;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_lock(&philo->data->lock);
	philo->data->total_meals += 1;
	pthread_mutex_unlock(&philo->data->lock);
	if (philo->data->dead == 0)
		message(philo->data, THINKING, philo->id);
}
