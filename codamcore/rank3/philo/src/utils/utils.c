/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/20 14:22:37 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_ms(void)
{
	struct timeval	tv;
	int				time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}

void	timestamp_msg(t_data *philo, int event, int id)
{
	int				time_ms;

	time_ms = get_time_ms();
	pthread_mutex_lock(&philo->write);
	if (event == EATING)
		ft_printf("%d %d is eating\n", time_ms - philo->timestamp_ms, id);
	else if (event == THINKING)
		ft_printf("%d %d is thinking\n", time_ms - philo->timestamp_ms, id);
	else if (event == SLEEPING)
		ft_printf("%d %d is sleeping\n", time_ms - philo->timestamp_ms, id);
	else if (event == DEAD)
		ft_printf("%d %d died\n", time_ms - philo->timestamp_ms, id);
	else if (event == FORK)
		ft_printf("%d %d has taken a fork\n", time_ms - philo->timestamp_ms, id);
	pthread_mutex_unlock(&philo->write);
	if (event == EATING || event == FORK)
	{
		philo->all_philos[id - 1].last_action = get_time_ms();
	}
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
