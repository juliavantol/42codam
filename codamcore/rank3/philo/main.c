/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/11 13:41:37 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	*make_philo(void *arg)
{
	int	id;

	id = *(int *)arg;
	ft_printf("%d\n", id);
	return (NULL);
}

int	philosophers(t_philo philo, int i)
{
	while (i < philo.number_of_philosophers)
	{
		if (pthread_mutex_init(&philo.forks[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < philo.number_of_philosophers)
	{
		philo.philosophers[i].id = i + 1;
		pthread_create(&philo.philosophers[i].thread, NULL, make_philo, &philo.philosophers[i].id);
		i++;
	}
	i = 0;
	while (i < philo.number_of_philosophers)
		pthread_join(philo.philosophers[i++].thread, NULL);
	i = 0;
	while (i < philo.number_of_philosophers)
		pthread_mutex_destroy(&philo.forks[i++]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo			philo;

	if (check_input(argc) == -1)
		return (EXIT_FAILURE);
	philo = fill_struct(argc, argv);
	if (valid_input(philo) == -1)
		return (EXIT_FAILURE);
	philosophers(philo, 0);
	return (0);
}
