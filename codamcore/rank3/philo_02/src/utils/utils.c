/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/01 14:29:28 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(t_data *data, int state, int id)
{
	u_int64_t	time;

	time = get_time_ms() - data->start_time;
	if (data->finished != 1)
	{
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
void	ft_usleep(t_data *data, u_int64_t duration)
{
	u_int64_t	start;

	if (data->finished != 1)
	{
		start = get_time_ms();
		while ((get_time_ms() - start) < duration)
			usleep(duration / 10);
	}
	return ;
}
