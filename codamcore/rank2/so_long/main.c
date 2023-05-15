/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:17:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/15 13:13:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system ("leaks so_long");
}

int	main(int argc, char	**argv)
{
	int			file;
	t_game		game;

	// atexit(leaks);
	if (argc != 2)
		ft_error("Not enough arguments\n");
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		ft_error("Invalid file\n");
	game = init_game(file, argv[1]);
	fill_grid(game.map, &game);
	close(file);
	open_window(game);
}
