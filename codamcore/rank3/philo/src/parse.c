/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 16:37:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/06/15 16:59:23 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_structs(t_philo *philo)
{
	pthread_mutex_t	mutex;
	t_philosopher	new_philo;
	t_fork			fork;
	int				index;

	index = 0;
	while (index < philo->number_of_philosophers)
	{
		fork.available = true;
		if (pthread_mutex_init(&mutex, NULL) != 0)
			return ;
		fork.mutex = mutex;
		philo->all_forks[index] = fork;
		new_philo.state = THINKING;
		philo->philosophers[index] = new_philo;
		index++;
	}
}

void	show_philos(t_philo philo)
{
	int				index;

	index = 0;
	while (index < philo.number_of_philosophers)
	{
		printf("%d\n", philo.philosophers[2].state);
		index++;
	}
}
