/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:17:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/28 12:46:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	int		map;

	if (argc != 2)
		ft_error("Not enough arguments\n");
	map = open(argv[1], O_RDONLY);
	if (map < 0)
		ft_error("Invalid file\n");
	//check_map(map);
	close(map);
	open_window();
}
