/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/17 17:37:20 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *data, int philo, int fork, char *hand)
{
	pthread_mutex_lock(&data->forks[fork]);
	ft_printf("\n %d has taken fork %d in their %s hand\n", philo, fork, hand);
}

void	down_fork(t_philo *data, int fork1, int fork2)
{
	pthread_mutex_unlock(&data->forks[fork1]);
	pthread_mutex_unlock(&data->forks[fork2]);
}

void	*eat(void *args)
{
	t_p	*data;

	data = (t_p *)args;
	while (1)
	{
		timestamp_msg(data->data, THINKING, data->id);
		if (data->data->number_of_times_to_eat == 1)
		{
			if (data->meals >= data->data->max_meals)
				break;
		}
		pthread_mutex_lock(data->left);
		timestamp_msg(data->data, FORK, data->id);
		if (data->id > 1)
		{
			pthread_mutex_lock(data->right);
			timestamp_msg(data->data, FORK, data->id);
		}
		timestamp_msg(data->data, EATING, data->id);
		data->meals += 1;
		usleep(data->data->time_to_eat * 1000);
		pthread_mutex_unlock(data->left);
		if (data->id > 1)
			pthread_mutex_unlock(data->right);
		timestamp_msg(data->data, SLEEPING, data->id);
		usleep(data->data->time_to_sleep * 1000);
	}
	return (NULL);
	
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	data;

	if (check_input(argc) == -1)
		return (EXIT_FAILURE);
	parse(argc, argv, &data);
	if (valid_input(data) == -1)
	{
		ft_printf("Invalid input\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	data.philosopher = 1;
	data.p = 1;
	while (i < data.number_of_philosophers)
	{
		data.left = i + 1;
		data.right = (i + 1 )% data.number_of_philosophers;
		if (pthread_create(&(data.threads[i]), NULL, &eat, &data.all_philos[i]) != 0)
			return (EXIT_FAILURE);
		data.philosopher += 1;
		data.p += 1;
		i++;
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		if (pthread_mutex_destroy(&data.forks[i]) != 0)
			ft_printf("error\n");
		i++;
	}
	return (0);
}
