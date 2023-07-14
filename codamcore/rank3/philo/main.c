/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/14 02:16:13 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int				counter;

void	*eat(void *args)
{
	t_philo	*data;
	int left;
	int right;

	data = (t_philo *)args;
	pthread_mutex_lock(&data->philos[data->p]);
	left = data->philosopher;
	right = (data->philosopher - 1) % data->number_of_philosophers;;
	printf("philo: %d left: %d right: %d\n", data->philosopher, left, right);
	pthread_mutex_lock(&data->forks[data->p]);
	ft_printf("\n %d is eating\n", data->philosopher);
	usleep(data->time_to_eat * 1000);
	ft_printf("\n %d is sleeping\n", data->philosopher);
	pthread_mutex_unlock(&data->forks[data->p]);
	pthread_mutex_unlock(&data->philos[data->p]);
	data->philosopher += 1;
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
		i++;
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	return (0);
}
