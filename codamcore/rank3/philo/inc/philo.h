/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:31:47 by Julia         #+#    #+#                 */
/*   Updated: 2023/08/22 00:57:13 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <string.h>

# define EATING "is eating"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define DEAD "died"
# define FORK "has taken a fork"
# define DIED -1

typedef struct s_philosopher
{
	int				id;
	int				meals;
	struct s_data	*data;
	bool			enough;
	pthread_mutex_t	lock;
	u_int64_t		last_meal;
}	t_philosopher;

typedef struct s_data
{
	int				philo_count;
	int				meal_count;
	int				dead;
	int				die_time;
	int				sleep_time;
	int				eat_time;
	int				total_meals;
	int				finished_philos;
	bool			max_meals;
	u_int64_t		start_time;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	t_philosopher	*philos;
	pthread_t		*threads;
}	t_data;

int			ft_error(t_data *data, char *str, int err_code);
int			parse_input(int argc, char **argv, t_data *philo);
int			init_threads(t_data	*data, int i);
int			eat_meal(t_philosopher *philo);
int			ft_strcmp(char *s1, char *s2);
int			init_struct(t_data *data, int index);
int			ft_atoi(const char *str);
int			ft_strlen(const char *s);
int			ft_exit(t_data *data, int code);
int			ft_isdigit(int c);
u_int64_t	get_time_ms(void);

void		destroy_mutexes(t_data *data, int i, int code);
void		message(t_data *data, char *state, int id);
void		ft_usleep(t_data *data, u_int64_t duration);
void		*philo_routine(void *args);
void		*supervisor(void *args);

bool		is_dead(t_data *data);
bool		all_eaten(t_data *data);

#endif
