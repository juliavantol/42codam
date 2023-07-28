/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/28 22:46:45 by Julia         ########   odam.nl         */
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
