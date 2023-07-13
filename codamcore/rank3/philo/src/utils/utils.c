/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/13 12:57:50 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timestamp_in_ms(t_philo philo, int event, int id)
{
	struct timeval	time;
	int				time_ms;

	gettimeofday(&time, NULL);
	time_ms = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	if (event == EATING)
		ft_printf("%d %d is eating\n", time_ms - philo.timestamp_ms, id);
	else if (event == THINKING)
		ft_printf("%d %d is thinking\n", time_ms - philo.timestamp_ms, id);
	else if (event == SLEEPING)
		ft_printf("%d %d is sleeping\n", time_ms - philo.timestamp_ms, id);
	else if (event == DEAD)
		ft_printf("%d %d died\n", time_ms - philo.timestamp_ms, id);
	else if (event == FORK)
		ft_printf("%d %d has taken a fork\n", time_ms - philo.timestamp_ms, id);
}

int valid_input(t_philo philo)
{
	if (philo.number_of_philosophers < 1 || philo.number_of_times_to_eat < 1
		|| philo.time_to_die < 1 || philo.time_to_eat < 1
		|| philo.number_of_times_to_eat < 1)
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
