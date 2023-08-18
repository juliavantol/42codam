/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/18 17:57:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	all_finished(t_data *data)
{
	pthread_mutex_lock(&data->lock);
	if (data->max_meals == true
		&& data->total_meals == (data->philo_count * data->meal_count))
	{
		data->dead = 1;
		pthread_mutex_unlock(&data->lock);
		return (true);
	}
	pthread_mutex_unlock(&data->lock);
	return (false);
}

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
	time = get_time_ms() - data->start_time;
	if (ft_strcmp(state, DEAD) == 1 && is_dead(data) == false)
	{
		if (all_finished(data) == false)
			printf("%llu %d %s\n", time, id, state);
		pthread_mutex_lock(&data->lock);
		data->dead = 1;
		pthread_mutex_unlock(&data->lock);
	}
	else if (is_dead(data) == false)
	{
		if (all_finished(data) == false)
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
			usleep(700);
		current_time = get_time_ms() - data->start_time;
	}
	return ;
}
