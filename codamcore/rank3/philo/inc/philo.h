/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:31:47 by Julia         #+#    #+#                 */
/*   Updated: 2023/08/07 13:53:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
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
	int				dead;
	struct s_data	*data;
	pthread_mutex_t	lock;
	u_int64_t		last_active;
}	t_philosopher;

typedef struct s_data
{
	int				philo_count;
	int				status;
	int				finished;
	int				meal_count;
	int				meals;
	int				dead;
	int				die_time;
	int				sleep_time;
	int				eat_time;
	int				total_meals;
	u_int64_t		start_time;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	pthread_t		*philo_threads;
	pthread_t		supervisor;
	t_philosopher	*philos;
}	t_data;

int			ft_strcmp(char *s1, char *s2);
int			parse_input(int argc, char **argv, t_data *philo);
int			init_struct(t_data *data);
int			ft_atoi(const char *str);
u_int64_t	get_time_ms(void);

void		message(t_data *data, char *state, int id, u_int64_t time2);
void		eat_meal(t_philosopher *philo);
void		init_threads(t_data	*data);
void		*philo_routine(void *args);
void		ft_usleep(t_data *data, u_int64_t duration);

#endif
