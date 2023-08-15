/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:31:47 by Julia         #+#    #+#                 */
/*   Updated: 2023/08/15 13:31:41 by juvan-to      ########   odam.nl         */
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
	int				dead;
	struct s_data	*data;
	pthread_mutex_t	lock;
	u_int64_t		last_active;
}	t_philosopher;

typedef struct s_data
{
	int				philo_count;
	int				status;
	int				meal_count;
	bool			max_meals;
	int				dead;
	int				die_time;
	int				sleep_time;
	int				eat_time;
	int				total_meals;
	u_int64_t		start_time;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	t_philosopher	*philos;
	pthread_t		*philo_threads;
}	t_data;

int			ft_strcmp(char *s1, char *s2);
int			parse_input(int argc, char **argv, t_data *philo);
int			ft_error(char *str, t_data *data);
int			eat_meal(t_philosopher *philo);
int			init_threads(t_data	*data);
int			init_struct(t_data *data);
int			ft_atoi(const char *str);
int			ft_strlen(const char *s);
int			ft_isdigit(int c);
u_int64_t	get_time_ms(void);

void		message(t_data *data, char *state, int id);
void		*philo_routine(void *args);
void		ft_usleep(t_data *data, u_int64_t duration);
void		free_all(t_data *data);

bool		is_dead(t_data *data);

#endif
