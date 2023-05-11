/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 14:39:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/11 17:40:53 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	fill_with_one(int **grid, int x, int y, t_map map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	grid[x - 1][y] = 1;
// 	grid[x + 1][y] = 1;
// 	grid[x][y - 1] = 1;
// 	grid[x][y + 1] = 1;
// 	while (i < map.height)
// 	{
// 		j = 0;
// 		while (j < map.width)
// 		{
// 			printf("%d ", grid[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

void	print_grid(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			printf("%c ", game->temp_grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	fill_with_one(t_game *game, int x, int y)
{
	if (game->temp_grid[x][y] == '1' || game->temp_grid[x][y] == 'E')
		return ;
	
	game->temp_grid[x][y] = '1';
	fill_with_one(game, x - 1, y);
	fill_with_one(game, x + 1, y);
	fill_with_one(game, x, y - 1);
	fill_with_one(game, x, y + 1);
}

void	fill_grid(t_map map, t_game game)
{
	char	**temp_grid;
	int	i;
	int j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	temp_grid = (char **)malloc(map.height * sizeof(char *));
	while (i < map.height)
	{
		temp_grid[i] = ft_strdup(map.map[i]);
		i++;
	}
	game.temp_grid = temp_grid;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (temp_grid[i][j] == 'P')
			{
				x = i;
				y = j;
			}
			j++;
		}
		i++;
	}
	fill_with_one(&game, x, y);
	print_grid(&game);
}
