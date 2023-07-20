/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/20 23:33:54 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timestamp_msg(t_data *philo, int event, int id)
{
	int				time_ms;

	time_ms = get_time_ms();
	pthread_mutex_lock(&philo->write);
	if (event == EATING)
		ft_printf("%d %d is eating\n", time_ms - philo->timestamp_ms, id);
	else if (event == THINKING)
		ft_printf("%d %d is thinking\n", time_ms - philo->timestamp_ms, id);
	else if (event == SLEEPING)
		ft_printf("%d %d is sleeping\n", time_ms - philo->timestamp_ms, id);
	else if (event == DEAD)
		ft_printf("%d %d died\n", time_ms - philo->timestamp_ms, id);
	else if (event == FORK)
		ft_printf("%d %d has taken a fork\n", time_ms - philo->timestamp_ms, id);
	pthread_mutex_unlock(&philo->write);
	if (event == EATING || event == FORK)
	{
		philo->all_philos[id - 1].last_action = get_time_ms();
	}
}

void	*waiter(void *args)
{
	t_waiter	*waiter;

	waiter = (t_waiter *)args;
	//pthread_mutex_lock(&waiter->lock);
	pthread_mutex_lock(&waiter->data->data->write);
	ft_printf("\nhey\n");
	pthread_mutex_unlock(&waiter->data->data->write);
	//pthread_mutex_unlock(&waiter->lock);
	return (NULL);
}

void	eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left);
	timestamp_msg(philo->data, FORK, philo->id);
	if (philo->id > 1)
	{
		pthread_mutex_lock(philo->right);
		timestamp_msg(philo->data, FORK, philo->id);
	}
	pthread_mutex_lock(&philo->data->lock);
	timestamp_msg(philo->data, EATING, philo->id);
	philo->meals += 1;
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_unlock(philo->left);
	if (philo->id > 1)
		pthread_mutex_unlock(philo->right);
}

void	*philosopher(void *args)
{
	t_philosopher			*philo;
	t_waiter	waiter_d;
	pthread_t	waiter_thread;

	philo = (t_philosopher *)args;
	waiter_d.data = philo;
	pthread_mutex_init(&waiter_d.lock, NULL);
	pthread_create(&waiter_thread, NULL, &waiter, &waiter_d);
	while (1)
	{
		timestamp_msg(philo->data, THINKING, philo->id);
		if (philo->data->number_of_times_to_eat == 1)
		{
			if (philo->meals >= philo->data->max_meals)
				break;
		}
		eat(philo);
		timestamp_msg(philo->data, SLEEPING, philo->id);
		usleep(philo->data->time_to_sleep * 1000);
		pthread_join(waiter_thread, NULL);
		pthread_mutex_destroy(&waiter_d.lock);
	}
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
