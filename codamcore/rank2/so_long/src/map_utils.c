/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 19:10:07 by Julia         #+#    #+#                 */
/*   Updated: 2023/05/15 13:13:11 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* Checks if all the characters in the line are valid */
void	valid_character(t_map *data, char *line, int height)
{
	int		index;

	index = 0;
	while (line[index])
	{
		if (line[index] == 'P')
		{
			data->start += 1;
			data->start_y = index;
			data->start_x = height;
		}
		else if (line[index] == 'C')
			data->collectibles += 1;
		else if (line[index] == 'E')
		{
			data->exit += 1;
			data->exit_y = index;
			data->exit_x = height;
		}
		if (line[index] != 'P' && line[index] != 'C' && line[index] != 'E'
			&& line[index] != '0' && line[index] != '1' && line[index] != '\n')
			ft_error("Map contains invalid components\n");
		index++;
	}
}

void	check_walls(t_game game, int i, int j)
{
	while (game.map.map[i][j])
	{
		if (game.map.map[i][j++] != '1')
			ft_error("Map not surrounded by walls\n");
	}
	j = 0;
	while (i < game.map.height)
	{
		if (game.map.map[i++][j] != '1')
			ft_error("Map not surrounded by walls\n");
	}
	i = game.map.height - 1;
	while (game.map.map[i][j])
	{
		if (game.map.map[i][j++] != '1')
			ft_error("Map not surrounded by walls\n");
	}
	i = 0;
	j = game.map.width - 1;
	while (i < game.map.height)
	{
		if (game.map.map[i++][j] != '1')
			ft_error("Map not surrounded by walls\n");
	}
}
