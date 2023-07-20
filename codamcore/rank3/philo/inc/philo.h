/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:31:47 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/20 23:33:19 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <string.h>
# include "printf/ft_printf.h"

# define EATING 1
# define THINKING 2
# define SLEEPING 3
# define DEAD 4
# define FORK 5

typedef struct s_philosopher
{
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct	s_data *data;
	int				meals;
	int				last_action;
	int				dead;
	int				id;
}	t_philosopher;

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_to_eat;
	int				max_meals;
	int				timestamp_ms;
	pthread_mutex_t	*philo_locks;
	int				left;
	int				right;
	pthread_t		*threads;
	pthread_t		waiter;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	t_philosopher				*all_philos;
}	t_data;

typedef struct s_waiter
{
	t_philosopher	*data;
	pthread_mutex_t	lock;
}	t_waiter;

void	parse(int argc, char **argv, t_data *philo);
void	timestamp_msg(t_data *philo, int event, int id);
void	put_str(char *str, int fd);
void	ft_error(char *msg);
void	put_char(char c);
int 	valid_input(t_data philo);
int 	check_input(int argc);
int		get_time_ms(void);

#endif
