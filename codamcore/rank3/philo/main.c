/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/06/06 14:05:00 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void)
{
	printf("Test from threads\n");
	usleep(3000);
	printf("End thread\n");
	return (0);
}

t_philo	fill_struct(int argc, char **argv)
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
	return (philo);
}

int	main(int argc, char **argv)
{
	t_philo		philo;
	pthread_t	thread1;
	pthread_t	thread2;

	if (argc != 5 && argc != 6)
	{
		put_str("Not enough arguments\n", 2);
		return (EXIT_FAILURE);
	}
	philo = fill_struct(argc, argv);
	if (philo.number_of_philosophers < 1 || philo.number_of_times_to_eat < 1
		|| philo.time_to_die < 1 || philo.time_to_eat < 1
		|| philo.number_of_times_to_eat < 1)
		return (EXIT_FAILURE);
	pthread_create(&thread1, NULL, (void *)routine, NULL);
	pthread_create(&thread2, NULL, (void *)routine, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return (0);
}
