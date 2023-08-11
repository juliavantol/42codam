void	*supervisor_routine(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	while (1)
	{
		pthread_mutex_lock(&data->lock);
		if (data->status == data->philo_count || data->finished == 1)
		{
			pthread_mutex_unlock(&data->lock);
			return (NULL);
		}
		ft_usleep(data, 1000);
		pthread_mutex_unlock(&data->lock);
	}
	return (NULL);
}

void	*death_patrol(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	while (philo->data->status != 1)
	{
		if (philo->data->meals == 1 && philo->meals == philo->data->meal_count)
		{
			break ;
		}
		if (get_time_ms() - philo->data->start_time
			> philo->last_active + philo->data->die_time)
		{
			message(philo->data, DEAD, philo->id);
			pthread_mutex_lock(&philo->lock);
			philo->dead = 1;
			pthread_mutex_unlock(&philo->lock);
			pthread_mutex_lock(&philo->data->lock);
			philo->data->status = -1;
			philo->data->finished = 1;
			pthread_mutex_unlock(&philo->data->lock);
			return ((void *)0);
		}
	}
	return ((void *)0);
}

void	*philo_routine(void *args)
{
	t_philosopher	*philo;
	pthread_t		p;

	philo = (t_philosopher *)args;
	pthread_create(&p, NULL, &death_patrol, (void *)philo);
	while (philo->data->finished != 1 && philo->dead != 1)
	{
		eat_meal(philo);
		if (philo->data->meals == 1 && philo->meals >= philo->data->meal_count)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->status += 1;
			pthread_mutex_unlock(&philo->data->lock);
			break ;
		}
	}
	pthread_join(p, NULL);
	return (NULL);
}

void	init_threads(t_data	*data)
{
	int			index;

	index = 0;
	pthread_create(&data->supervisor, NULL, &supervisor_routine, (void *)data);
	while (index < data->philo_count)
	{
		pthread_create(&(data->philo_threads[index]), NULL,
			&philo_routine, (void *)&data->philos[index]);
		index++;
		ft_usleep(data, 1000);
	}
	index = 0;
	while (index < data->philo_count)
		pthread_join(data->philo_threads[index++], NULL);
	pthread_join(data->supervisor, NULL);
	return ;
}

void	take_forks(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[left]);
		message(philo->data, FORK, philo->id);
		pthread_mutex_lock(&philo->data->forks[right]);
		message(philo->data, FORK, philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[right]);
		message(philo->data, FORK, philo->id);
		pthread_mutex_lock(&philo->data->forks[left]);
		message(philo->data, FORK, philo->id);
	}
}

void	put_forks_down(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->data->forks[left]);
		pthread_mutex_unlock(&philo->data->forks[right]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->forks[right]);
		pthread_mutex_unlock(&philo->data->forks[left]);
	}
}

void	eat_meal(t_philosopher *philo)
{
	take_forks(philo);
	message(philo->data, EATING, philo->id);
	pthread_mutex_lock(&philo->lock);
	philo->last_active = get_time_ms() - philo->data->start_time;
	ft_usleep(philo->data, philo->data->eat_time * 1000);
	pthread_mutex_unlock(&philo->lock);
	put_forks_down(philo);
	pthread_mutex_lock(&philo->lock);
	philo->meals += 1;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_lock(&philo->data->lock);
	philo->data->total_meals += 1;
	pthread_mutex_unlock(&philo->data->lock);
	message(philo->data, SLEEPING, philo->id);
	ft_usleep(philo->data, philo->data->sleep_time * 1000);
	message(philo->data, THINKING, philo->id);

}