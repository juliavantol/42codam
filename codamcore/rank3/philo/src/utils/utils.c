/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/23 13:49:31 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Checks if someone should die */
bool	should_die(t_data *data)
{
	bool		die;
	u_int64_t	time;
	int			i;

	i = 0;
	while (i < data->philo_count)
	{
		time = get_time_ms() - data->start_time;
		pthread_mutex_lock(&data->philos[i].lock);
		die = time > data->philos[i].last_meal + data->die_time;
		pthread_mutex_unlock(&data->philos[i].lock);
		if (die == true)
		{
			message(data, DEAD, data->philos[i].id);
			return (true);
		}
		i++;
	}
	return (false);
}

/* Checks if someone has died */
bool	all_eaten(t_data *data)
{
	bool	finished;

	pthread_mutex_lock(&data->lock);
	finished = (data->max_meals && data->finished_philos == data->philo_count);
	pthread_mutex_unlock(&data->lock);
	return (finished);
}

/* Checks if someone has died or if everyone has eaten */
bool	is_dead(t_data *data)
{
	bool	dead;

	pthread_mutex_lock(&data->dead_lock);
	dead = data->dead == 1;
	pthread_mutex_unlock(&data->dead_lock);
	return (dead);
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
		pthread_mutex_lock(&data->dead_lock);
		data->dead = 1;
		pthread_mutex_unlock(&data->dead_lock);
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
		usleep(800);
		current_time = get_time_ms() - data->start_time;
	}
	return ;
}
