void	*supervisor_routine(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	while (1)
	{
		pthread_mutex_lock(&data->write);
		printf("\n\nfinish status: %d\n\n", data->finished);
		pthread_mutex_unlock(&data->write);
		if (data->finished == data->philo_count) 
		{
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

void	*philo_routine(void *args)
{
	t_philosopher	*philo;
	int				meals_eaten;

	philo = (t_philosopher *)args;
	while (1)
	{
		take_forks(philo);
		eat_meal(philo);
		put_forks_down(philo);
		message(philo->data, SLEEPING, philo->id);
		usleep(philo->data->sleep_time * 1000);
		message(philo->data, THINKING, philo->id);
		pthread_mutex_lock(&philo->lock);
		meals_eaten = philo->meals;
		pthread_mutex_unlock(&philo->lock);
		if (philo->data->meals == 1 && philo->meals >= philo->data->meal_count)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished += 1;
			pthread_mutex_unlock(&philo->data->lock);
			philo->data->supervisor_t->status += 1;
			break ;
		}
	}
	return (NULL);
}

void	init_threads(t_data	*data)
{
	int				index;
	t_supervisor	*supervisor_t;

	index = 0;
	supervisor_t = malloc(sizeof(t_supervisor));
	supervisor_t->status = 0;
	supervisor_t->data = data;
	data->supervisor_t = supervisor_t;
	pthread_create(&(data->supervisor), NULL,
		&supervisor_routine, &data);
	data->status = STARTED;
	while (index < data->philo_count)
	{
		pthread_create(&(data->philo_threads[index]), NULL,
			&philo_routine, &data->philos[index]);
		index++;
		usleep(1000);
	}
	index = 0;
	while (index < data->philo_count)
		pthread_join(data->philo_threads[index++], NULL);
	pthread_join(data->supervisor, NULL);
}