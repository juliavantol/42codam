/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:17:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/11 16:31:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system ("leaks so_long");
}

int	main(int argc, char	**argv)
{
	int			map;
	t_game		game;
	t_map		map_data;
	t_node		*collectibles;

	// atexit(leaks);
	if (argc != 2)
		ft_error("Not enough arguments\n");
	map = open(argv[1], O_RDONLY);
	if (map < 0)
		ft_error("Invalid file\n");
	map_data = check_map(map, 0, 0, 0);
	map_data.file = argv[1];
	map_data.map = fill_map(map_data);
	game.map = map_data;
	fill_grid(map_data, game);
	exit(1);
	game.moves = 0;
	collectibles = (t_node *) malloc(sizeof(t_node));
	collectibles = NULL;
	game.collectibles = collectibles;
	close(map);
	open_window(game);
}
