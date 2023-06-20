/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 16:37:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/06/20 12:03:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_structs(t_philo *philo)
{
	// pthread_mutex_t	mutex;
	t_philosopher	new_philo;
	t_fork			fork;
	int				index;

	index = 0;
	while (index < philo->number_of_philosophers + 1)
	{
		fork.id = index;
		fork.available = true;
		// pthread_mutex_init(&mutex, NULL);
		// if (pthread_mutex_init(&mutex, NULL) != 0)
		// 	return ;
		// fork.mutex = mutex;
		philo->all_forks[index] = fork;
		new_philo.state = THINKING;
		philo->philosophers[index] = new_philo;
		index++;
	}
}

void	link_forks(t_philo *philo)
{
	int	index;
	int	last;

	index = 0;
	last = philo->number_of_philosophers - 1;
	while (index < philo->number_of_philosophers)
	{
		if (index > 0 && index < philo->number_of_philosophers)
		{
			philo->philosophers[index].fork_left = &philo->all_forks[index + 1];
			philo->philosophers[index].fork_right = &philo->all_forks[index];
		}
		index++;
	}
	philo->philosophers[0].fork_left = &philo->all_forks[1];
	philo->philosophers[0].fork_right = &philo->all_forks[last];
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
