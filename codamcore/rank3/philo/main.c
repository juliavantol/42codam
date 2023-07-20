/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/20 14:31:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*waiter(void *args)
{
	t_waiter	*waiter;
	int	time;

	waiter = (t_waiter *)args;
	time = get_time_ms();
	pthread_mutex_lock(&waiter->data->write);
	printf("\nhey\n");
	pthread_mutex_unlock(&waiter->data->write);
	return (NULL);
}

void	eat(t_philosopher *data)
{
	pthread_mutex_lock(data->left);
	timestamp_msg(data->data, FORK, data->id);
	if (data->id > 1)
	{
		pthread_mutex_lock(data->right);
		timestamp_msg(data->data, FORK, data->id);
	}
	pthread_mutex_lock(&data->data->lock);
	timestamp_msg(data->data, EATING, data->id);
	data->meals += 1;
	usleep(data->data->time_to_eat * 1000);
	pthread_mutex_unlock(&data->data->lock);
	pthread_mutex_unlock(data->left);
	if (data->id > 1)
		pthread_mutex_unlock(data->right);
}

void	*philosopher(void *args)
{
	t_philosopher			*data;
	t_waiter	*waiter_d;
	pthread_t	waiter_thread;

	data = (t_philosopher *)args;
	waiter_d = malloc(sizeof(t_waiter));
	waiter_d->data = data->data;
	pthread_mutex_init(&waiter_d->lock, NULL);
	pthread_create(&waiter_thread, NULL, &waiter, &waiter_d);
	while (1)
	{
		timestamp_msg(data->data, THINKING, data->id);
		if (data->data->number_of_times_to_eat == 1)
		{
			if (data->meals >= data->data->max_meals)
				break;
		}
		eat(data);
		timestamp_msg(data->data, SLEEPING, data->id);
		usleep(data->data->time_to_sleep * 1000);
	}
	pthread_join(waiter_thread, NULL);
    pthread_mutex_destroy(&waiter_d->lock);
	return (NULL);
	
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	if (check_input(argc) == -1)
		return (EXIT_FAILURE);
	parse(argc, argv, &data);
	if (valid_input(data) == -1)
	{
		ft_printf("Invalid input\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		data.left = i + 1;
		data.right = (i + 1 )% data.number_of_philosophers;
		if (pthread_create(&(data.threads[i]), NULL, &philosopher, &data.all_philos[i]) != 0)
			return (EXIT_FAILURE);
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
