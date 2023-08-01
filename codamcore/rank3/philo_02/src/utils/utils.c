/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/01 22:27:19 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(t_data *data, char *state, int id)
{
	u_int64_t	time;

	time = get_time_ms() - data->start_time;
	//printf("\nstart: %s status: %d\n", state, data->dead);
	pthread_mutex_lock(&data->write);
	if (ft_strcmp(state, DEAD) == 1 && data->dead == 0)
	{
		printf("%llu %d %s\n", time, id, state);
		data->dead = 1;
	}
	else if (data->dead == 0)
		printf("%llu %d %s\n", time, id, state);
	//printf("leave: %s status: %d\n", state, data->dead);
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
void	ft_usleep(t_data *data, u_int64_t duration)
{
	u_int64_t	start;

	usleep(duration);
	return ;
	if (data->finished != 1)
	{
		start = get_time_ms();
		while ((get_time_ms() - start) < duration)
			usleep(duration / 10);
	}
	return ;
}

int	len(char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	if (len(s1) != len(s2))
		return (0);
	while (s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	return (1);
}
