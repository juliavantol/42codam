/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/11 12:42:31 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	fill_struct(int argc, char **argv, struct timeval time)
{
	t_philo	philo;

	philo.number_of_philosophers = ft_atoi(argv[1]);
	philo.number_of_times_to_eat = ft_atoi(argv[2]);
	philo.time_to_die = ft_atoi(argv[3]);
	philo.time_to_eat = ft_atoi(argv[4]);
	if (argc == 6)
		philo.number_of_times_to_eat = ft_atoi(argv[5]);
	else
		philo.number_of_times_to_eat = 1;
	philo.timestamp_ms = (time.tv_sec) * 1000 + (time.tv_usec) / 1000 ;
	philo.all_forks = malloc(sizeof(t_fork) * philo.number_of_philosophers);
	philo.philosophers = malloc(sizeof(t_philosopher)
			* philo.number_of_philosophers);
	philo.forks = malloc(sizeof(pthread_mutex_t) * philo.number_of_philosophers);
	return (philo);
}

void	*make_philo(void *arg)
{
	int	id;

	id = *(int *)arg;
	ft_printf("%d\n", id);
	return (NULL);
}

int	main(int argc, char **argv)
{
	struct timeval	time;
	int				i;
	int				j;
	t_philo			philo;

	if (argc != 5 && argc != 6)
	{
		put_str("Not enough arguments\n", 2);
		return (EXIT_FAILURE);
	}
	gettimeofday(&time, NULL);
	philo = fill_struct(argc, argv, time);
	if (philo.number_of_philosophers < 1 || philo.number_of_times_to_eat < 1
		|| philo.time_to_die < 1 || philo.time_to_eat < 1
		|| philo.number_of_times_to_eat < 1)
		return (EXIT_FAILURE);
	i = 0;
	while (i < philo.number_of_philosophers)
	{
		if (pthread_mutex_init(&philo.forks[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	j = 0;
	i = 1;
	ft_printf("hey\n");
	while (j < philo.number_of_philosophers)
	{
		philo.philosophers[j].id = i;
		pthread_create(&philo.philosophers[j].thread, NULL, make_philo, &philo.philosophers[j].id);
		j++;
		i++;
	}
	i = 0;
	while (i < philo.number_of_philosophers)
	{
		pthread_join(philo.philosophers[i].thread, NULL);
		i++;
	}
	// parse_structs(&philo);
	// link_forks(&philo);
	// show_philos(philo);
	return (0);
}
