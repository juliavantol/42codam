/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 15:15:38 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/06/15 16:49:56 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_philo(t_philos **philosophers, int index)
{
	t_philosopher	philo;
	t_philos		*head;

	philo.id = index;
	philo.fork_left = index - 1;
	philo.fork_right = index + 1;
	philo.state = THINKING;
	head = malloc(sizeof(t_philos));
	head->philo = philo;
	head->next = *philosophers;
	*philosophers = head;
}

void	make_forks(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->number_of_philosophers)
	{
		add_philo(&(philo->philosophers), index);
		index++;
	}
}
