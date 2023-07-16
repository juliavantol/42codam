/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/16 21:21:20 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *data, int philo, int fork, char *hand)
{
	pthread_mutex_lock(&data->forks[fork]);
	ft_printf("\n %d has taken fork %d in their %s hand\n", philo, fork, hand);
}

void	down_fork(t_philo *data, int fork1, int fork2)
{
	pthread_mutex_unlock(&data->forks[fork1]);
	pthread_mutex_unlock(&data->forks[fork2]);
}


void	*eat(void *args)
{
	t_philo	*data;
	int left;
	int right;

	// thinking
	// eating
	data = (t_philo *)args;
	while (1)
	{
		left = data->philosopher - 1;
		right = ((data->philosopher - 1) % data->number_of_philosophers) - 1;
		// printf("%d l: %d r: %d\n", data->philosopher, left, right);
		pthread_mutex_lock(&data->forks[left]);
		pthread_mutex_lock(&data->forks[right]);
		pthread_mutex_lock(&data->philos[data->p]);
		timestamp_in_ms(data, EATING, data->philosopher);
		//ft_printf("\n %d is eating\n", data->philosopher);
		pthread_mutex_unlock(&data->philos[data->p]);
		usleep(data->time_to_eat * 1000);
		pthread_mutex_lock(&data->philos[data->p]);
		//ft_printf("\n %d is sleeping\n", data->philosopher);
		timestamp_in_ms(data, SLEEPING, data->philosopher);
		pthread_mutex_unlock(&data->philos[data->p]);
		pthread_mutex_unlock(&data->forks[right]);
		pthread_mutex_unlock(&data->forks[left]);
	}
	return (NULL);
	
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	data;

	if (check_input(argc) == -1)
		return (EXIT_FAILURE);
	parse(argc, argv, 0, &data);
	if (valid_input(data) == -1)
		return (EXIT_FAILURE);
	i = 0;
	data.philosopher = 1;
	data.p = 1;
	while (i < data.number_of_philosophers)
	{
		data.left = i + 1;
		data.right = (i + 1 )% data.number_of_philosophers;
		if (pthread_create(&(data.threads[i]), NULL, &eat, &data) != 0)
			return (EXIT_FAILURE);
		data.philosopher += 1;
		i++;
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		if (pthread_mutex_destroy(&data.forks[i]) != 0)
			ft_printf("error\n");
		i++;
	}
	return (0);
}
