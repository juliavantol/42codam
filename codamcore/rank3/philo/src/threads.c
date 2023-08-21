/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/21 17:02:52 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Joins the threads */
int	join_threads(t_data *data, int i)
{
	while (i < data->philo_count)
	{
		if (pthread_join(data->threads[i++], NULL) != 0)
			return (ft_error(data, "Error joining thread", 2));
	}
	return (0);
}

/* Detach threads in case of error */
void	detach_threads(t_data *data, int i)
{
	int	index;

	index = 0;
	while (index < i)
		pthread_detach(data->threads[index++]);
}

/* Creates and joins the supervisor thread and all the philo threads */
int	init_threads(t_data	*data, int i)
{
	pthread_t	p;

	if (pthread_create(&p, NULL, &supervisor, (void *)data) != 0)
		return (ft_error(data, "Error creating thread", 2));
	while (i < data->philo_count)
	{
		if (pthread_create(&(data->threads[i]), NULL,
				&philo_routine, (void *)&data->philos[i]) != 0)
			break ;
		i++;
	}
	if (i != data->philo_count)
	{
		detach_threads(data, i);
		return (ft_error(data, "Error creating thread", 2));
	}
	join_threads(data, 0);
	if (pthread_join(p, NULL) != 0)
		return (ft_error(data, "Error joining thread", 2));
	return (0);
}
