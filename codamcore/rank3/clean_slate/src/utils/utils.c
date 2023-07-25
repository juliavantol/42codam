/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/25 13:42:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(t_data *data, int state)
{
	pthread_mutex_lock(&data->write);
	if (state == EATING)
		ft_printf("is eating\n");
	else if (state == SLEEPING)
		ft_printf("is sleeping\n");
	else if (state == THINKING)
		ft_printf("is thinking\n");
	pthread_mutex_unlock(&data->write);
}

void	init_threads(t_data	data)
{
	int	index;

	index = 0;
	while (index < data.philo_count)
	{
		pthread_create(&(data.philo_threads[index]), NULL, &eating, &data);
		index++;
	}
	index = 0;
	while (index < data.philo_count)
		pthread_join(data.philo_threads[index++], NULL);
}
