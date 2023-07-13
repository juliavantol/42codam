/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   example.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/07/13 12:00:07 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int				counter;
pthread_mutex_t	lock;

void	*loop(void *args)
{
	unsigned long	i;

	pthread_mutex_lock(&lock);
	i = 0;
	counter += 1;
	printf("\n job %d has started\n", counter);
	while (i < (0xFFFFFFFF))
		i++;
	printf("\n job %d has finished\n", counter);
	pthread_mutex_unlock(&lock);
	return (NULL);
	
}

int	main(int argc, char **argv)
{
	int				i;
	pthread_t		*threads;
	t_philo	philo;

	if (check_input(argc) == -1)
		return (EXIT_FAILURE);
	philo = fill_struct(argc, argv);
	if (valid_input(philo) == -1)
		return (EXIT_FAILURE);
	threads = malloc(sizeof(pthread_t) * philo.number_of_philosophers);
	if (pthread_mutex_init(&lock, NULL) != 0)
		return (EXIT_FAILURE);
	i = 0;
	while (i < 2)
	{
		if (pthread_create(&(threads[i]), NULL, &loop, NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return (0);
}
