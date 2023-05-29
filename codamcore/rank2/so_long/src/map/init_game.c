/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:40:14 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/29 14:39:28 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initialises the map struct */
t_map	init_map(int file, char *filename)
{
	t_map	map;
	char	*line;
	char	*all_lines;

	map.exit = 0;
	map.start = 0;
	map.free_tiles = 0;
	map.free_tiles2 = NULL;
	map.collectibles = 0;
	map.file_name = filename;
	map.file = file;
	line = get_next_line(map.file);
	if (!line)
		ft_error("Empty line\n");
	map.width = (ft_strlen(line) - 1);
	all_lines = "";
	map = check_characters(map, 0, all_lines, line);
	return (map);
}

/* Initialises the game struct */
t_game	init_game(int file, char *filename)
{
	t_game	game;

	game.map = init_map(file, filename);
	game.collectibles = NULL;
	game.moves = 0;
	game.display = NULL;
	game.loop = 1;
	game.direction = 'd';
	game.mice = NULL;
	game.mlx = NULL;
	set_collectible_paths(&game);
	check_walls(game, 0, 0);
	if (game.map.width == game.map.height)
		ft_error("Map must be rectangular\n");
	return (game);
}

/* Checks if all the characters in the map are valid and stores
the map in a double pointer */
t_map	check_characters(t_map map, int length, char *all_lines, char *line)
{
	char	*temp;

	while (line)
	{
		valid_character(&map, line, length, 0);
		temp = all_lines;
		all_lines = ft_strjoin(temp, line);
		if (!all_lines)
			ft_error("Strjoin\n");
		if (ft_strlen(temp) != 0)
			free(temp);
		free(line);
		line = get_next_line(map.file);
		length++;
	}
	if (map.start != 1 || map.exit != 1 || map.collectibles < 1)
		ft_error("Invalid number of map components\n");
	map.height = length;
	map.map = ft_split(all_lines, '\n');
	if (!map.map)
		ft_error("Split\n");
	free(all_lines);
	return (map);
}
