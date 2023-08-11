#include "philo.h"

// make && ./philo 5 2000 500 500 -- no one should die but they do

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_input(argc, argv, &data) == -1)
	{
		printf("Invalid input\n");
		exit(1);
	}
	data.start_time = get_time_ms();
	init_struct(&data);
	init_threads(&data);
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
	data->total_meals = 0;
	data->meals = 0;
	data->status = 0;
	data->finished = 0;
	data->dead = 0;
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
		data->philos[index].last_active = 0;
		pthread_mutex_init(&data->philos[index].lock, NULL);
		pthread_mutex_init(&data->forks[index], NULL);
		index++;
	}
	return (1);
}
void	take_forks(t_philosopher *philo, u_int64_t time)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	if (philo->data->dead != 0)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[left]);
		message(philo->data, FORK, philo->id, time);
		pthread_mutex_lock(&philo->data->forks[right]);
		message(philo->data, FORK, philo->id, time);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[right]);
		message(philo->data, FORK, philo->id, time);
		pthread_mutex_lock(&philo->data->forks[left]);
		message(philo->data, FORK, philo->id, time);
	}
}

void	put_forks_down(t_philosopher *philo, u_int64_t time)
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
	//pthread_mutex_lock(&philo->data->lock);
	if (philo->data->dead == 0)
	{
		message(philo->data, SLEEPING, philo->id, time);
		ft_usleep(philo->data, philo->data->sleep_time);
	}
	// pthread_mutex_unlock(&philo->data->lock);
}

void	eat_meal(t_philosopher *philo)
{
	u_int64_t	time;

	time = get_time_ms() - philo->data->start_time;
	take_forks(philo, time);
	time = get_time_ms() - philo->data->start_time;
	message(philo->data, EATING, philo->id, time);
	pthread_mutex_lock(&philo->lock);
	philo->last_active = get_time_ms() - philo->data->start_time;
	pthread_mutex_unlock(&philo->lock);
	ft_usleep(philo->data, philo->data->eat_time);
	time = get_time_ms() - philo->data->start_time;
	put_forks_down(philo, time);
	pthread_mutex_lock(&philo->lock);
	philo->meals += 1;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_lock(&philo->data->lock);
	philo->data->total_meals += 1;
	pthread_mutex_unlock(&philo->data->lock);
}

void	*supervisor_routine(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	while (data->dead == 0)
	{
		pthread_mutex_lock(&data->lock);
		if (data->status == data->philo_count)
		{
			pthread_mutex_unlock(&data->lock);
			return (NULL);
		}
		pthread_mutex_unlock(&data->lock);
	}
	return (NULL);
}

void	*death_patrol(void *args)
{
	t_philosopher	*philo;
	u_int64_t		time;

	philo = (t_philosopher *)args;
	while (philo->data->dead == 0)
	{
		time = get_time_ms() - philo->data->start_time;
		if (time > philo->last_active + philo->data->die_time)
		{
			message(philo->data, DEAD, philo->id, time);
			return ((void *)0);
		}
		if (philo->data->meals == 1 && philo->meals == philo->data->meal_count)
			return ((void *)0);
	}
	return ((void *)0);
}

void	*philo_routine(void *args)
{
	t_philosopher	*philo;
	pthread_t		p;

	philo = (t_philosopher *)args;
	pthread_create(&p, NULL, &death_patrol, (void *)philo);
	while (philo->data->dead == 0)
	{
		eat_meal(philo);
		if (philo->data->dead == 0)
		{
			pthread_mutex_lock(&philo->data->lock);
			message(philo->data, THINKING, philo->id, get_time_ms() - philo->data->start_time);
			pthread_mutex_unlock(&philo->data->lock);
		}
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
	}
	index = 0;
	while (index < data->philo_count)
		pthread_join(data->philo_threads[index++], NULL);
	pthread_join(data->supervisor, NULL);
	return ;
}

void	message(t_data *data, char *state, int id, u_int64_t time2)
{
	u_int64_t	time;

	pthread_mutex_lock(&data->write);
	if (ft_strcmp(state, DEAD) == 1 && data->dead == 0)
	{
		time = get_time_ms() - data->start_time;
		printf("%llu %d %s\n", time2, id, state);
		data->dead = 1;
	}
	else if (data->dead == 0)
	{
		time = get_time_ms() - data->start_time;
		printf("%llu %d %s\n", time2, id, state);
	}
	pthread_mutex_unlock(&data->write);
}

// gets time in miliseconds
u_int64_t	get_time_ms(void)
{
	struct timeval	tv;
	u_int64_t		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}

//  a custom usleep function which asks for the time constantly in
// a while loop until the time specified has passed
void	ft_usleep(t_data *data, u_int64_t duration)
{
	u_int64_t	current_time;
	u_int64_t	goal_time;

	current_time = get_time_ms() - data->start_time;
	goal_time = current_time + duration;
	if (data->dead != 1)
	{
		while (1)
		{
			if (current_time >= goal_time)
				break ;
			else
				usleep(500);
			current_time = get_time_ms() - data->start_time;
		}
		return ;
	}
	return ;
}

int	len(char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	if (len(s1) != len(s2))
		return (0);
	while (s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	return (1);
}