/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/24 17:54:04 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// make && ./philo 44 300 200 100
// make && ./philo 1 200 100 100

#include "philo.h"

void	timestamp_msg(t_data *philo, int event, int id)
{
	int				time_ms;

	time_ms = get_time_ms();
	if (philo->finished != 1)
	{
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
}

void	*waiter(void *args)
{
    int				num_philosophers;
	t_data			*data;
	t_waiter		*waiter;
	t_philosopher	*philosophers;
	t_philosopher	*philo;
	int				time_elapsed;
	int				i;

	data = (t_data *)args;
	num_philosophers = data->number_of_philosophers;
	waiter = data->waiter;
	philosophers = data->all_philos;
	while (1)
    {
		i = 0;
		while (i < num_philosophers)
        {
            philo = &philosophers[i];

            pthread_mutex_lock(&philo->lock);
            time_elapsed = get_time_ms() - philo->end_action;
			if (time_elapsed > philo->data->time_to_die || (philo->start_action == 0 
				&& get_time_ms() >  philo->data->time_to_die))
            {
                timestamp_msg(philo->data, DEAD, philo->id);
				data->finished = 1;
				waiter->done = 1;
                philo->dead = 1;
            }
            pthread_mutex_unlock(&philo->lock);
			i++;
        }
        pthread_mutex_lock(&waiter->lock);
        if (waiter->done == 1)
        {
            pthread_mutex_unlock(&waiter->lock);
            break;
        }
        pthread_mutex_unlock(&waiter->lock);
    }
	return (NULL);
}

void	*philosopher(void *args)
{
	t_philosopher			*philo;
	t_data					*data;
	
	philo = (t_philosopher *)args;
	data = philo->data;
	while (philo->data->finished == 0)
	{
		if (data->number_of_times_to_eat == 1)
		{
			if (philo->meals >= data->max_meals)
			{
				pthread_mutex_lock(&data->lock);
				philo->dead = 1;
				philo->data->finished += 1;
				pthread_mutex_unlock(&data->lock);
				break;
			}
		}
		if (data->finished != 1)
		{
			eat(philo);
			timestamp_msg(data, SLEEPING, philo->id);
			usleep(philo->data->time_to_sleep * 1000);
			timestamp_msg(philo->data, THINKING, philo->id);
		}
	}
	return (NULL);
	
}

int	main(int argc, char **argv)
{
	int			i;
	t_data		data;
	t_waiter	*waiter_s;
	pthread_t	waiter_thread;

	if (check_input(argc) == -1)
		return (EXIT_FAILURE);
	parse(argc, argv, &data);
	if (valid_input(data) == -1)
	{
		ft_printf("Invalid input\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	waiter_s = (t_waiter *)malloc(sizeof(t_waiter));
	waiter_s->done = 0;
	data.waiter = waiter_s;
	pthread_mutex_init(&waiter_s->lock, NULL);
	pthread_create(&waiter_thread, NULL, &waiter, &data);
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
	pthread_join(waiter_thread, NULL);
	i = 0;
	pthread_mutex_destroy(&waiter_s->lock);
	while (i < data.number_of_philosophers)
	{
		if (pthread_mutex_destroy(&data.forks[i]) != 0)
			ft_printf("error\n");
		i++;
	}
	return (0);
}
