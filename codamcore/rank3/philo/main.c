/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/22 15:06:35 by juvan-to      ########   odam.nl         */
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
}

void	*waiter(void *args)
{
	t_waiter	*waiter;
	int			time;
	int			end_action;

	waiter = (t_waiter *)args;
	while (waiter->data->dead == 0)
	{
		pthread_mutex_lock(&waiter->data->data->write);
		time = get_time_ms() - waiter->data->data->start_time;
		if (waiter->data->end_action != 0)
		{
			end_action = waiter->data->end_action - waiter->data->data->start_time;
			ft_printf("ID %d Time: %d -- Last action: %d\n", waiter->data->id, time, end_action);	
		}	
		pthread_mutex_unlock(&waiter->data->data->write);
	}
	return (NULL);
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
			{
				philo->dead = 1;
				philo->data->finished = 1;
				break;	
			}
		}
		eat(philo);
		timestamp_msg(philo->data, SLEEPING, philo->id);
		usleep(philo->data->time_to_sleep * 1000);
	}
	pthread_join(waiter_thread, NULL);
	pthread_mutex_destroy(&waiter_d.lock);
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
