/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/21 17:41:24 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Checks if someone has died */
bool	all_eaten(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->philos[i].lock);
		if (data->max_meals == true && data->philos[i].enough == false)
		{
			pthread_mutex_unlock(&data->philos[i].lock);
			return (false);
		}
		pthread_mutex_unlock(&data->philos[i].lock);
		i++;
	}
	return (true);
}

/* Checks if someone has died or if everyone has eaten */
bool	is_dead(t_data *data)
{
	pthread_mutex_lock(&data->lock);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->lock);
		return (true);
	}
	pthread_mutex_unlock(&data->lock);
	if (data->max_meals == true && all_eaten(data) == true)
		return (true);
	return (false);
}

/* Print the message with the current timestamp */
void	message(t_data *data, char *state, int id)
{
	u_int64_t	time;

	time = get_time_ms() - data->start_time;
	pthread_mutex_lock(&data->write);
	if (ft_strcmp(state, DEAD) == 1 && is_dead(data) == false)
	{
		printf("%llu %d %s\n", time, id, state);
		pthread_mutex_lock(&data->lock);
		data->dead = 1;
		pthread_mutex_unlock(&data->lock);
	}
	else if (is_dead(data) == false)
		printf("%llu %d %s\n", time, id, state);
	pthread_mutex_unlock(&data->write);
}

/* Get current time in milliseconds */
u_int64_t	get_time_ms(void)
{
	struct timeval	tv;
	u_int64_t		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}

/* Custom usleep that keeps checking the time until goal time is reached */
void	ft_usleep(t_data *data, u_int64_t duration)
{
	u_int64_t	current_time;
	u_int64_t	goal_time;

	current_time = get_time_ms() - data->start_time;
	goal_time = current_time + duration;
	while (current_time < goal_time && is_dead(data) == false)
	{
		usleep(500);
		current_time = get_time_ms() - data->start_time;
	}
	return ;
}
