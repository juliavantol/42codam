/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/25 23:24:34 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eating(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	while (1)
	{
		message(philo->data, EATING, philo->id);
		pthread_mutex_lock(&philo->lock);
		philo->meals += 1;
		pthread_mutex_unlock(&philo->lock);
		usleep(philo->data->eat_time * 1000);
		message(philo->data, SLEEPING, philo->id);
		usleep(philo->data->sleep_time * 1000);
		if (philo->data->meals == 1 && philo->meals >= philo->data->meal_count)
			break ;
	}
	return (NULL);
}

void	message(t_data *data, int state, int id)
{
	u_int64_t	time;

	time = get_time_ms() - data->start_time;
	pthread_mutex_lock(&data->write);
	if (state == EATING)
		printf("%llu %d is eating\n", time, id);
	else if (state == SLEEPING)
		printf("%llu %d is sleeping\n", time, id);
	else if (state == THINKING)
		printf("%llu %d is thinking\n", time, id);
	pthread_mutex_unlock(&data->write);
}

void	init_threads(t_data	data)
{
	int	index;

	index = 0;
	while (index < data.philo_count)
	{
		pthread_create(&(data.philo_threads[index]), NULL,
			&eating, &data.philos[index]);
		index++;
	}
	index = 0;
	while (index < data.philo_count)
		pthread_join(data.philo_threads[index++], NULL);
}

u_int64_t	get_time_ms(void)
{
	struct timeval	tv;
	u_int64_t		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}
