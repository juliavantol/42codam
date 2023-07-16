/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 16:37:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/16 21:14:10 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse(int argc, char **argv, int i, t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_to_eat = ft_atoi(argv[5]);
	else
		philo->number_of_times_to_eat = 1;
	philo->timestamp_ms = (time.tv_sec) * 1000 + (time.tv_usec) / 1000 ;
	philo->threads = malloc(sizeof(pthread_t) * philo->number_of_philosophers);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->number_of_philosophers);
	philo->philos = malloc(sizeof(pthread_mutex_t) * philo->number_of_philosophers);
	pthread_mutex_init(&philo->write, NULL);
	i = 0;
	while (i < philo->number_of_philosophers)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
			ft_printf("error\n");
		if (pthread_mutex_init(&philo->philos[i], NULL) != 0)
			ft_printf("error\n");
		i++;
	}
}
