void	take_forks(t_philosopher *philo)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	//printf("%d left: %d right: %d\n", philo->id, left, right);
	if (philo->id % 2 == 0)
	{
		// right fork first
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
		//left fork first
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
		// right fork first
		pthread_mutex_unlock(&philo->data->forks[left]);
		pthread_mutex_unlock(&philo->data->forks[right]);
	}
	else
	{
		//left fork first
		pthread_mutex_unlock(&philo->data->forks[right]);
		pthread_mutex_unlock(&philo->data->forks[left]);
	}
}

void	eat_meal(t_philosopher *philo)
{
	message(philo->data, EATING, philo->id);
	pthread_mutex_lock(&philo->lock);
	philo->meals += 1;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_lock(&philo->data->lock);
	philo->data->total_meals += 1;
	pthread_mutex_unlock(&philo->data->lock);
	usleep(philo->data->eat_time * 1000);
	message(philo->data, SLEEPING, philo->id);
	usleep(philo->data->sleep_time * 1000);
	message(philo->data, THINKING, philo->id);
}

void	*eating(void *args)
{
	t_philosopher	*philo;
	int				meals_eaten;

	philo = (t_philosopher *)args;
	while (1)
	{
		take_forks(philo);
		eat_meal(philo);
		put_forks_down(philo);
		pthread_mutex_lock(&philo->lock);
		meals_eaten = philo->meals;
		pthread_mutex_unlock(&philo->lock);
		if (philo->data->meals == 1 && philo->meals >= philo->data->meal_count)
		{
			break ;
		}
	}
	return (NULL);
}

void	init_threads(t_data	*data)
{
	int	index;

	index = 0;
	while (index < data->philo_count)
	{
		pthread_create(&(data->philo_threads[index]), NULL,
			&eating, &data->philos[index]);
		index++;
	}
	index = 0;
	while (index < data->philo_count)
		pthread_join(data->philo_threads[index++], NULL);
}


int	parse_input(int argc, char **argv, t_data *data)
{
	if (argc != 6 && argc != 5)
		return (-1);
	data->philo_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->meal_count = 1;
	data->finished = 0;
	data->total_meals = 0;
	data->meals = 0;
	if (argc == 6)
	{
		data->meal_count = ft_atoi(argv[5]);
		data->meals = 1;
	}
	if (!data->philo_count || !data->die_time || !data->eat_time
		|| !data->sleep_time || !data->meal_count)
		return (-1);
	if (data->philo_count < 1 || data->die_time < 1 || data->eat_time < 1
		|| data->sleep_time < 1 || data->meal_count < 1)
		return (-1);
	return (1);
}

int	init_struct(t_data *data)
{
	int	index;

	data->philo_threads = malloc(sizeof(pthread_t) * data->philo_count);
	data->philos = malloc(sizeof(t_philosopher) * data->philo_count);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	index = 0;
	while (index < data->philo_count)
	{
		data->philos[index].id = index + 1;
		data->philos[index].data = data;
		data->philos[index].dead = 0;
		data->philos[index].meals = 0;
		pthread_mutex_init(&data->philos[index].lock, NULL);
		pthread_mutex_init(&data->forks[index], NULL);
		index++;
	}
	return (1);
}

int	parse_input(int argc, char **argv, t_data *data)
{
	if (argc != 6 && argc != 5)
		return (-1);
	data->philo_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->meal_count = 1;
	data->finished = 0;
	data->total_meals = 0;
	data->meals = 0;
	if (argc == 6)
	{
		data->meal_count = ft_atoi(argv[5]);
		data->meals = 1;
	}
	if (!data->philo_count || !data->die_time || !data->eat_time
		|| !data->sleep_time || !data->meal_count)
		return (-1);
	if (data->philo_count < 1 || data->die_time < 1 || data->eat_time < 1
		|| data->sleep_time < 1 || data->meal_count < 1)
		return (-1);
	return (1);
}

int	init_struct(t_data *data)
{
	int	index;

	data->philo_threads = malloc(sizeof(pthread_t) * data->philo_count);
	data->philos = malloc(sizeof(t_philosopher) * data->philo_count);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	index = 0;
	while (index < data->philo_count)
	{
		data->philos[index].id = index + 1;
		data->philos[index].data = data;
		data->philos[index].dead = 0;
		data->philos[index].meals = 0;
		pthread_mutex_init(&data->philos[index].lock, NULL);
		pthread_mutex_init(&data->forks[index], NULL);
		index++;
	}
	return (1);
}

void	message(t_data *data, int state, int id)
{
	u_int64_t	time;

	time = get_time_ms() - data->start_time;
	pthread_mutex_lock(&data->write);
	if (state == EATING)
		printf("%llu %d is eating\n", time, id);
	else if (state == SLEEPING)
		printf("%llu %d is sleeping\n", time, id);
	else if (state == THINKING)
		printf("%llu %d is thinking\n", time, id);
	else if (state == FORK)
		printf("%llu %d has taken a fork\n", time, id);
	pthread_mutex_unlock(&data->write);
}

u_int64_t	get_time_ms(void)
{
	struct timeval	tv;
	u_int64_t		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_input(argc, argv, &data) == -1)
	{
		ft_printf("Invalid input\n");
		exit(1);
	}
	data.start_time = get_time_ms();
	init_struct(&data);
	init_threads(&data);
}
