/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 16:37:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/11 17:13:18 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	fill_struct(int argc, char **argv)
{
	t_philo			philo;
	struct timeval	time;

	gettimeofday(&time, NULL);
	philo.number_of_philosophers = ft_atoi(argv[1]);
	philo.number_of_times_to_eat = ft_atoi(argv[2]);
	philo.time_to_die = ft_atoi(argv[3]);
	philo.time_to_eat = ft_atoi(argv[4]);
	if (argc == 6)
		philo.number_of_times_to_eat = ft_atoi(argv[5]);
	else
		philo.number_of_times_to_eat = 1;
	philo.timestamp_ms = (time.tv_sec) * 1000 + (time.tv_usec) / 1000 ;
	philo.philosophers = malloc(sizeof(t_philosopher)
			* philo.number_of_philosophers);
	philo.forks = malloc(sizeof(pthread_mutex_t) * philo.number_of_philosophers);
	return (philo);
}

void	show_philos(t_philo philo)
{
	int	i;

	i = 0;
	while (i < philo.number_of_philosophers)
	{
		printf("%d <-- %d --> %d\n", philo.philosophers[i].fork_left->id, i, philo.philosophers[i].fork_right->id);
		i++;
	}
}
