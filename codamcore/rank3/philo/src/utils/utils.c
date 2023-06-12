/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/06/12 12:52:07 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timestamp_in_ms(t_philo philo)
{
	struct timeval	time;
	int				time_ms;

	gettimeofday(&time, NULL);
	time_ms = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	ft_putnum(time_ms - philo.timestamp_ms);
	put_str("\n", 1);
}
