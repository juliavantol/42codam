/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:31:47 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/25 14:25:42 by juvan-to      ########   odam.nl         */
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

typedef struct s_philosopher
{
	int				id;
	struct t_data	*data;
}	t_philosopher;

typedef struct s_data
{
	int				philo_count;
	int				meal_count;
	int				die_time;
	int				sleep_time;
	int				eat_time;
	pthread_mutex_t	write;
	pthread_t		*philo_threads;
	t_philosopher	*philos;
}	t_data;

int		parse_input(int argc, char **argv, t_data *philo);
int		init_mutexes(t_data *data);
int		init_structs(t_data *data);

void	init_threads(t_data	data);
void	message(t_data *data, int state);
void	*eating(void *args);

#endif
