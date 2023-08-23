/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/17 19:05:52 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/23 17:11:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Destroy specific mutexes, either the forks or the locks */
void	destroy_mutexes(t_data *data, int max, int code)
{
	int	index;

	index = 0;
	while (index < max)
	{
		if (code == 1)
		{
			if (data->forks != 0)
				pthread_mutex_destroy(&data->forks[index]);
		}
		else
		{
			if (data->philos != 0)
				pthread_mutex_destroy(&data->philos[index].lock);
		}
		index++;
	}
}

/* Clean all the mutexes in the philos struct */
void	clean_all_mutexes(t_data *data, int code)
{
	int	index;

	index = 0;
	if (code > 1)
	{
		while (index < data->philo_count)
		{
			if (data->forks != 0)
				pthread_mutex_destroy(&data->forks[index]);
			if (data->philos != 0)
				pthread_mutex_destroy(&data->philos[index].lock);
			index++;
		}
	}
}

/* Clean up all the data */
int	ft_exit(t_data *data, int code)
{
	if (code > 1)
	{
		pthread_mutex_destroy(&data->write);
		pthread_mutex_destroy(&data->lock);
		pthread_mutex_destroy(&data->dead_lock);
		clean_all_mutexes(data, code);
	}
	if (data->threads != 0)
		free(data->threads);
	if (data->philos != 0)
		free(data->philos);
	if (data->forks != 0)
		free(data->forks);
	return (0);
}

/* Print error message and proceed to clean the data */
int	ft_error(t_data *data, char *str, int err_code)
{
	printf("%s\n", str);
	ft_exit(data, err_code);
	return (0);
}
