/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/31 16:40:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	else if (state == FORK)
		printf("%llu %d has taken a fork\n", time, id);
	else if (state == DEAD)
		printf("%llu %d has died\n", time, id);
	pthread_mutex_unlock(&data->write);
}

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
void	ft_usleep(t_data *data, int duration)
{
	u_int64_t	goal_time;
	u_int64_t	current_time;

	if (data->status != -1)
	{
		goal_time = get_time_ms() + duration;
		while (1)
		{
			current_time = get_time_ms();
			if (current_time >= goal_time)
				break ;
		}
	}
}
