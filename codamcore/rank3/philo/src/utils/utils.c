/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/11 15:41:46 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	message(t_data *data, char *state, int id)
{
	u_int64_t	time;

	pthread_mutex_lock(&data->write);
	if (ft_strcmp(state, DEAD) == 1 && data->dead == 0)
	{
		time = get_time_ms() - data->start_time;
		printf("%llu %d %s\n", time, id, state);
		data->dead = 1;
	}
	else if (data->dead == 0)
	{
		time = get_time_ms() - data->start_time;
		printf("%llu %d %s\n", time, id, state);
	}
	pthread_mutex_unlock(&data->write);
}

// gets time in miliseconds
u_int64_t	get_time_ms(void)
{
	struct timeval	tv;
	u_int64_t		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}

//  a custom usleep function which asks for the time constantly in
// a while loop until the time specified has passed
void	ft_usleep(t_data *data, u_int64_t duration)
{
	u_int64_t	current_time;
	u_int64_t	goal_time;

	current_time = get_time_ms() - data->start_time;
	goal_time = current_time + duration;
	while (1)
	{
		if (current_time >= goal_time || data->dead == 1)
			break ;
		else
			usleep(500);
		current_time = get_time_ms() - data->start_time;
	}
	return ;
}
