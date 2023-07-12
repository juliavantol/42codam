/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/12 18:06:16 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eating(void *arg)
{
	int				id;
	// int				index;
	int				turns;
	int				left;
	int 			right;
	t_philo			*philo;
	
	// time_start = 
	philo = (t_philo *)arg;
	id = philo->index + 1;
	// index = philo->index;
	left = id;
	right = (id - 1) % philo->number_of_philosophers;
	if (right == 0)
		right = philo->number_of_philosophers;
	turns = 0;
	while (turns < philo->number_of_times_to_eat)
	{
		pthread_mutex_lock(&philo->forks[left - 1]);
		timestamp_in_ms(*philo, FORK, id);
		if (philo->number_of_philosophers > 1)
		{
			pthread_mutex_lock(&philo->forks[right - 1]);
			timestamp_in_ms(*philo, FORK, id);
		}
		timestamp_in_ms(*philo, EATING, id);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->forks[left - 1]);
		pthread_mutex_unlock(&philo->forks[right - 1]);
		timestamp_in_ms(*philo, SLEEPING, id);
		usleep(philo->time_to_sleep * 1000);
		timestamp_in_ms(*philo, THINKING, id);
		turns++;
	}
	return (NULL);
}


int	philosophers(t_philo philo)
{
	int			i;

	i = 0;
	while (i < philo.number_of_philosophers)
	{
		if (pthread_mutex_init(&philo.forks[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < philo.number_of_philosophers)
	{
		philo.index = i;
		pthread_create(&philo.philosophers[i].thread, NULL, eating, &philo);
		i++;
	}
	i = 0;
	while (i < philo.number_of_philosophers)
	{
		pthread_join(philo.philosophers[i].thread, NULL);
		i++;
	}
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
	philosophers(philo);
	return (0);
}
