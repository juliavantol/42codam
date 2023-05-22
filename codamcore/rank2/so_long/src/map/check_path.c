/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_path.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 14:39:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/22 22:30:57 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Fills the map with 1's until it has encountered a wall */
void	fill_with_one(t_game *game, int x, int y)
{
	if (game->temp_grid[x][y] == '1')
		return ;
	game->temp_grid[x][y] = '1';
	fill_with_one(game, x - 1, y);
	fill_with_one(game, x + 1, y);
	fill_with_one(game, x, y - 1);
	fill_with_one(game, x, y + 1);
}

/* Checks if the exit is accessible */
void	check_path(t_map map, t_game *game)
{
	char	**temp_grid;
	int		i;

	i = 0;
	temp_grid = (char **)malloc(map.height * sizeof(char *));
	while (i < map.height)
	{
		temp_grid[i] = ft_strdup(map.map[i]);
		i++;
	}
	game->temp_grid = temp_grid;
	fill_with_one(game, map.start_x, map.start_y);
	if (temp_grid[map.exit_x][map.exit_y] != '1')
		ft_error("No valid path\n");
	check_path_collectibles(game);
}

/* Checks if all the collectibles are accessible */
void	check_path_collectibles(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (game->map.map[x][y] == 'C')
			{
				if (game->temp_grid[x][y] != '1')
					ft_error("No valid path\n");
			}
			y++;
		}
		x++;
	}
}
