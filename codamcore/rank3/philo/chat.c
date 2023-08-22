int	take_forks(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	if (is_dead(philo->data) == true)
		return (-1);
	pthread_mutex_lock(&philo->data->forks[left]);
	message(philo->data, FORK, philo->id);
	if (left == right)
		return (-1);
	pthread_mutex_lock(&philo->data->forks[right]);
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
	if (philo->meals == philo->data->meal_count)
	{
		pthread_mutex_lock(&philo->data->lock);
		philo->data->finished_philos += 1;
		pthread_mutex_unlock(&philo->data->lock);
		philo->enough = true;
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
	while (current_time < goal_time && is_dead(data) == false)
	{
		usleep(300);
		current_time = get_time_ms() - data->start_time;
	}
	return ;
}
void	*supervisor(void *args)
{
	t_data		*data;

	data = (t_data *)args;
	while (is_dead(data) == false)
	{
		if (all_eaten(data) == true)
		{
			pthread_mutex_lock(&data->dead_lock);
			data->dead = 1;
			pthread_mutex_unlock(&data->dead_lock);
		}
		usleep(300);
	}
	return (0);
}

void	*reaper(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	while (is_dead(philo->data) == false)
	{
		if (should_die(philo) == true)
			message(philo->data, DEAD, philo->id);
		usleep(300);
	}
	return (0);
}

/* Keep eating and sleeping until max meals have been eaten
or until someone has died */
void	*philo_routine(void *args)
{
	t_philosopher	*philo;
	pthread_t		p;

	philo = (t_philosopher *)args;
	if (pthread_create(&p, NULL, &reaper, (void *)philo) != 0)
		return (0);
	if (philo->id % 2 == 0 && philo->data->philo_count != 1)
		ft_usleep(philo->data, philo->data->eat_time);
	while (is_dead(philo->data) == false)
	{
		if (eat_meal(philo) == -1)
		{
			pthread_join(p, NULL);
			return (0);
		}
	}
	pthread_join(p, NULL);
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
		detach_threads(data, i);
		return (ft_error(data, "Error creating thread", 2));
	}
	join_threads(data, 0);
	if (pthread_join(p, NULL) != 0)
		return (ft_error(data, "Error joining thread", 2));
	return (0);
}