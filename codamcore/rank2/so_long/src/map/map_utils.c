/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 19:10:07 by Julia         #+#    #+#                 */
/*   Updated: 2023/05/22 12:56:58 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checks if all the characters in the line are valid */
void	valid_character(t_map *data, char *line, int height, int i)
{
	if (if_empty_line(line) == 1)
		ft_error("Empty lines\n");
	while (line[i])
	{
		if (line[i] == 'P')
		{
			data->start += 1;
			data->start_y = i;
			data->start_x = height;
		}
		else if (line[i] == 'C')
			data->collectibles += 1;
		else if (line[i] == 'E')
		{
			data->exit += 1;
			data->exit_y = i;
			data->exit_x = height;
		}
		if (line[i] != 'P' && line[i] != 'C' && line[i] != 'E' && line[i] != 'X'
			&& line[i] != '0' && line[i] != '1' && line[i] != '\n')
			ft_error("Map contains invalid components\n");
		i++;
	}
}

int	check_walls(t_game game, int i, int j)
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
	return (1);
}
