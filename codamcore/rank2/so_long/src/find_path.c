/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 14:39:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/12 14:20:19 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	fill_grid(t_map map, t_game *game)
{
	char	**temp_grid;
	int	i;
	int j;

	i = 0;
	j = 0;
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
	// print_map(game.temp_grid);
	get_collectibles(game);
}
