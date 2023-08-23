bool	should_die(t_philosopher *philo)
{
	bool		die;
	u_int64_t	time;

	time = get_time_ms() - philo->data->start_time;
	pthread_mutex_lock(&philo->lock);
	die = time > philo->last_meal + philo->data->die_time;
	pthread_mutex_unlock(&philo->lock);
	return (die);
}

/* Checks if someone has died */
bool	all_eaten(t_data *data)
{
	bool	finished;

	pthread_mutex_lock(&data->lock);
	finished = (data->max_meals && data->finished_philos == data->philo_count);
	pthread_mutex_unlock(&data->lock);
	return (finished);
}

/* Checks if someone has died or if everyone has eaten */
bool	is_dead(t_data *data)
{
	bool	dead;

	pthread_mutex_lock(&data->dead_lock);
	dead = data->dead == 1;
	pthread_mutex_unlock(&data->dead_lock);
	return (dead);
}

/* Print the message with the current timestamp */
void	message(t_data *data, char *state, int id)
{
	u_int64_t	time;

	time = get_time_ms() - data->start_time;
	pthread_mutex_lock(&data->write);
	if (ft_strcmp(state, DEAD) == 1 && is_dead(data) == false)
	{
		printf("%llu %d %s\n", time, id, state);
		pthread_mutex_lock(&data->dead_lock);
		data->dead = 1;
		pthread_mutex_unlock(&data->dead_lock);
	}
	else if (is_dead(data) == false)
		printf("%llu %d %s\n", time, id, state);
	pthread_mutex_unlock(&data->write);
}

void	*supervisor(void *args)
{
	t_data		*data;
	int			i;

	data = (t_data *)args;
	while (is_dead(data) == false)
	{
		if (all_eaten(data) == true)
		{
			pthread_mutex_lock(&data->dead_lock);
			data->dead = 1;
			pthread_mutex_unlock(&data->dead_lock);
		}
		i = 0;
		while (i < data->philo_count)
		{
			if (should_die(&data->philos[i]) == true)
				message(data, DEAD, data->philos[i].id);
			i++;
		}
		usleep(1000);
	}
	return (0);
}

void	ft_usleep(t_data *data, u_int64_t duration)
{
	u_int64_t	current_time;
	u_int64_t	goal_time;

	current_time = get_time_ms() - data->start_time;
	goal_time = current_time + duration;
	while (current_time < goal_time && is_dead(data) == false)
	{
		usleep(800);
		current_time = get_time_ms() - data->start_time;
	}
	return ;
}