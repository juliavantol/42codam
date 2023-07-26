/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:31:47 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/26 14:11:52 by juvan-to      ########   odam.nl         */
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
# include "printf/ft_printf.h"

# define EATING 1
# define THINKING 2
# define SLEEPING 3
# define DEAD 4
# define FORK 5

typedef struct s_waiter
{
	struct s_data	*data;
	pthread_mutex_t	lock;
}	t_waiter;

typedef struct s_philosopher
{
	int				id;
	int				meals;
	int				dead;
	struct s_data	*data;
	pthread_mutex_t	lock;
}	t_philosopher;

typedef struct s_data
{
	int				philo_count;
	int				meal_count;
	int				meals;
	int				die_time;
	int				sleep_time;
	int				eat_time;
	int				finished;
	int				total_meals;
	u_int64_t		start_time;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	pthread_t		*philo_threads;
	t_philosopher	*philos;
}	t_data;

int			parse_input(int argc, char **argv, t_data *philo);
int			init_struct(t_data *data);
u_int64_t	get_time_ms(void);

void		message(t_data *data, int state, int id);
void		init_threads(t_data	*data);
void		*eating(void *args);

#endif
