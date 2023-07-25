/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/25 12:52:46 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// make && ./philo 44 300 200 100
// make && ./philo 1 200 100 100
// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
#include "philo.h"

void	*eating(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	pthread_mutex_lock(&data->write);
	ft_printf("hey\n");
	pthread_mutex_unlock(&data->write);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		index;

	if (parse_input(argc, argv, &data) == -1)
	{
		ft_printf("Invalid input\n");
		exit(1);
	}
	index = 0;
	while (index < data.philo_count)
	{
		if (pthread_create(&(data.philo_threads[index]), NULL
				, &eating, &data != 0)
			return (EXIT_FAILURE);
		index++;
	}
	index = 0;
	while (index < data.philo_count)
		pthread_join(data.philo_threads[index++], NULL);
}
