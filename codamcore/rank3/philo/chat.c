int	main(int argc, char **argv)
{
	t_data	data;

	//atexit(leaks);
	if (parse_input(argc, argv, &data) == -1)
		return (ft_error(&data, "Error: invalid input\n", 0));
	data.start_time = get_time_ms();
	if (init_struct(&data, 0) == -1)
		return (ft_error(&data, "Error\n", 1));
	init_threads(&data, 0);
	ft_exit(&data, 2);
	return (0);
}

int	take_forks(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	if (is_dead(philo->data) == true)
		return (-1);
	pthread_mutex_lock(&philo->data->forks[left]);
	if (left == right)
		return (-1);
	pthread_mutex_lock(&philo->data->forks[right]);
	message(philo->data, FORK, philo->id);
	message(philo->data, FORK, philo->id);
	return (1);
}

/* Unlocks the mutexes for the two forks after eating
increments the meal counters and starts sleeping */
void	put_forks_down(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	pthread_mutex_unlock(&philo->data->forks[right]);
	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_lock(&philo->lock);
	philo->meals += 1;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_lock(&philo->lock);
	if (philo->meals >= philo->data->meal_count)
	{
		pthread_mutex_lock(&philo->data->lock);
		philo->data->finished_philos += 1;
		pthread_mutex_unlock(&philo->data->lock);
	}
	pthread_mutex_unlock(&philo->lock);
	if (is_dead(philo->data) == false)
	{
		message(philo->data, SLEEPING, philo->id);
		ft_usleep(philo->data, philo->data->sleep_time);
	}
}

/* Take the forks, start eating and put the forks down again */
int	eat_meal(t_philosopher *philo)
{
	if (take_forks(philo) == -1)
		return (-1);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal = get_time_ms() - philo->data->start_time;
	pthread_mutex_unlock(&philo->lock);
	message(philo->data, EATING, philo->id);
	ft_usleep(philo->data, philo->data->eat_time);
	put_forks_down(philo);
	if (is_dead(philo->data) == false)
		message(philo->data, THINKING, philo->id);
	return (1);
}

bool	all_finished(t_data *data)
{
	pthread_mutex_lock(&data->lock);
	if (data->max_meals == true
		&& data->finished_philos >= data->philo_count)
	{
		pthread_mutex_unlock(&data->lock);
		return (true);
	}
	pthread_mutex_unlock(&data->lock);
	return (false);
}

/* Checks if someone has died */
bool	is_dead(t_data *data)
{
	pthread_mutex_lock(&data->lock);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->lock);
		return (true);
	}
	pthread_mutex_unlock(&data->lock);
	return (false);
}

/* Print the message with the current timestamp */
void	message(t_data *data, char *state, int id)
{
	u_int64_t	time;

	pthread_mutex_lock(&data->write);
	time = get_time_ms() - data->start_time;
	if (ft_strcmp(state, DEAD) == 1 && is_dead(data) == false)
	{
		printf("%llu %d %s\n", time, id, state);
		pthread_mutex_lock(&data->lock);
		data->dead = 1;
		pthread_mutex_unlock(&data->lock);
	}
	else if (is_dead(data) == false)
	{
		printf("%llu %d %s\n", time, id, state);
	}
	pthread_mutex_unlock(&data->write);
}

/* Get current time in milliseconds */
u_int64_t	get_time_ms(void)
{
	struct timeval	tv;
	u_int64_t		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}

/* Custom usleep that keeps checking the time until goal time is reached */
void	ft_usleep(t_data *data, u_int64_t duration)
{
	u_int64_t	current_time;
	u_int64_t	goal_time;

	current_time = get_time_ms() - data->start_time;
	goal_time = current_time + duration;
	while (1)
	{
		if (current_time >= goal_time || is_dead(data) == true
			|| all_finished(data) == true)
			break ;
		else
			usleep(700);
		current_time = get_time_ms() - data->start_time;
	}
	return ;
}

void	*supervisor(void *args)
{
	t_data		*data;
	int			i;

	data = (t_data *)args;
	while (is_dead(data) == false && all_finished(data) == false)
	{
		i = 0;
		while (i < data->philo_count && all_finished(data) == false)
		{
			pthread_mutex_lock(&data->philos[i].lock);
			if (get_time_ms() - data->start_time
				> data->philos[i].last_meal + data->die_time)
			{
				message(data, DEAD, data->philos[i].id);
				pthread_mutex_unlock(&data->philos[i].lock);
				return (0);
			}
			pthread_mutex_unlock(&data->philos[i].lock);
			i++;
		}
		usleep(700);
	}
	return (0);
}

/* Keep eating and sleeping until max meals have been eaten
or until someone has died */
void	*philo_routine(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	if (philo->id % 2 != 0 && philo->data->philo_count != 1)
		ft_usleep(philo->data, philo->data->eat_time);
	while (is_dead(philo->data) == false && all_finished(philo->data) == false)
	{
		if (eat_meal(philo) == -1)
			return (0);
	}
	return (0);
}

int	join_threads(t_data *data, int i)
{
	while (i < data->philo_count)
	{
		if (pthread_join(data->threads[i++], NULL) != 0)
			return (ft_error(data, "Error joining thread", 2));
	}
	return (0);
}

/* Detach threads in case of error */
void	detach_threads(t_data *data, int i)
{
	int	index;

	index = 0;
	while (index < i)
		pthread_detach(data->threads[index++]);
}

/* Creates and joins the supervisor thread and all the philo threads */
int	init_threads(t_data	*data, int i)
{
	pthread_t	p;

	if (pthread_create(&p, NULL, &supervisor, (void *)data) != 0)
		return (ft_error(data, "Error creating thread", 2));
	while (i < data->philo_count)
	{
		if (pthread_create(&(data->threads[i]), NULL,
				&philo_routine, (void *)&data->philos[i]) != 0)
			break ;
		i++;
	}
	if (i != data->philo_count)
	{
		pthread_detach(p);
		detach_threads(data, i);
		return (ft_error(data, "Error creating thread", 2));
	}
	join_threads(data, 0);
	if (pthread_join(p, NULL) != 0)
		return (ft_error(data, "Error joining thread", 2));
	return (0);
}