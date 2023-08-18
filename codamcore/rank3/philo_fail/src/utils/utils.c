/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/17 14:34:47 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Checks if someone has died */
bool	is_dead(t_data *data)
{
	pthread_mutex_lock(&data->lock);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->lock);
		return (true);
	}
	pthread_mutex_unlock(&data->lock);
	return (false);
}

/* Print the message with the current timestamp */
void	message(t_data *data, char *state, int id)
{
	u_int64_t	time;

	pthread_mutex_lock(&data->write);
	if (ft_strcmp(state, DEAD) == 1 && is_dead(data) == false)
	{
		time = get_time_ms() - data->start_time;
		printf("%llu %d %s\n", time, id, state);
		pthread_mutex_lock(&data->lock);
		data->dead = 1;
		pthread_mutex_unlock(&data->lock);
	}
	else if (is_dead(data) == false)
	{
		time = get_time_ms() - data->start_time;
		printf("%llu %d %s\n", time, id, state);
	}
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
	while (1)
	{
		if (current_time >= goal_time || is_dead(data) == true)
			break ;
		else
			usleep(500);
		current_time = get_time_ms() - data->start_time;
	}
	return ;
}