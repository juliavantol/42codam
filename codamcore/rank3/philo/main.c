/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/08/17 19:06:22 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_input(argc, argv, &data) == -1)
		return (ft_exit(&data, "Error: invalid input\n", 1));
	data.start_time = get_time_ms();
	if (init_struct(&data) == -1)
		return (ft_exit(&data, "Error\n", 1));
	init_threads(&data);
	ft_exit(&data, "\n", 2);
	return (0);
}
