/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 16:37:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/11 13:38:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Makes the forks and philosphers */
void	parse_structs(t_philo *philo)
{
	pthread_mutex_t	mutex;
	t_philosopher	new_philo;
	t_fork			fork;
	int				index;

	index = 0;
	while (index < philo->number_of_philosophers + 1)
	{
		fork.id = index;
		fork.available = true;
		if (pthread_mutex_init(&mutex, NULL) != 0)
			return ;
		fork.mutex = mutex;
		philo->all_forks[index] = fork;
		new_philo.state = THINKING;
		philo->philosophers[index] = new_philo;
		// pthread_create(&thread, NULL, &func, NULL);
		index++;
	}
}

/* Assign forks to the philosophers */
void	link_forks(t_philo *philo)
{
	int	index;
	int	last;

	index = 0;
	last = philo->number_of_philosophers;
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
