/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/24 17:45:26 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philosopher *philo)
{
	
	if (philo->data->finished != 1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->left]);
		timestamp_msg(philo->data, FORK, philo->id);
		if (philo->id > 1)
		{
			pthread_mutex_lock(&philo->data->forks[philo->right]);
			timestamp_msg(philo->data, FORK, philo->id);
		}
		pthread_mutex_lock(&philo->lock);
		philo->end_action = 0;
		philo->start_action = get_time_ms();
		philo->meals += 1;
		pthread_mutex_unlock(&philo->lock);
		timestamp_msg(philo->data, EATING, philo->id);
		if (philo->data->finished != 1)
			usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->data->forks[philo->left]);
		if (philo->id > 1)
			pthread_mutex_unlock(&philo->data->forks[philo->right]);
		philo->end_action = get_time_ms();
	}
}

int	get_time_ms(void)
{
	struct timeval	tv;
	int				time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}

int valid_input(t_data philo)
{
	if (philo.number_of_times_to_eat == 1)
	{
		if (philo.max_meals < 1)
			return (-1);
	}
	if (philo.number_of_philosophers < 1 || philo.time_to_die < 1
		|| philo.time_to_eat < 1)
		return (-1);
	return (0);
}

int check_input(int argc)
{
	if (argc != 5 && argc != 6)
	{
		put_str("Invalid number of arguments\n", 2);
		return (-1);
	}
	return (0);
}
