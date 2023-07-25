/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 16:37:30 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/25 14:30:00 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_input(int argc, char **argv, t_data *data)
{
	if (argc != 6 && argc != 5)
		return (-1);
	data->philo_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->meal_count = ft_atoi(argv[5]);
	else
		data->meal_count = 1;
	if (!data->philo_count || !data->die_time || !data->eat_time
		|| !data->sleep_time)
		return (-1);
	if (data->philo_count < 1 || data->die_time < 1 || data->eat_time < 1
		|| data->sleep_time < 1)
		return (-1);
	return (1);
}

int	init_mutexes(t_data *data)
{
	pthread_mutex_init(&data->write, NULL);
	return (1);
}

int	init_structs(t_data *data)
{
	int	index;

	data->philos = malloc(sizeof(t_philosopher) * data->philo_count);
	index = 0;
	while (index < data->philo_count)
	{
		data->philos[index].id = index;
		index++;
	}
	return (1);
}
