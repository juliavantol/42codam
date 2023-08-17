/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/17 19:05:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/17 19:06:24 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Clean up all the data */
int	ft_exit(t_data *data, char *str, int err_code)
{
	int	index;

	index = 0;
	if (err_code > 0)
		printf("%s\n", str);
	while (index < data->philo_count)
	{
		if (data->forks != 0)
			pthread_mutex_destroy(&data->forks[index]);
		if (data->philos != 0)
			pthread_mutex_destroy(&data->philos[index].lock);
		index++;
	}
	if (err_code > 1)
		pthread_mutex_destroy(&data->write);
	if (err_code > 1)
		pthread_mutex_destroy(&data->lock);
	if (data->philo_threads != 0)
		free(data->philo_threads);
	if (data->philos != 0)
		free(data->philos);
	if (data->forks != 0)
		free(data->forks);
	return (0);
}
