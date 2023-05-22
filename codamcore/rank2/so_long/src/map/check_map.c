/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:40:14 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/22 12:47:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initialises the map and game structs */
t_game	init_game(int file, char *filename)
{
	t_map	map;
	t_game	game;

	map.exit = 0;
	map.start = 0;
	map.collectibles = 0;
	map.file_name = filename;
	map.file = file;
	map = check_characters(map, 0);
	game.map = map;
	game.collectibles = NULL;
	game.moves = 0;
	set_foods(&game);
	check_walls(game, 0, 0);
	if (game.map.width == game.map.height)
		ft_error("Map must be rectangular\n");
	return (game);
}

/* Checks if all the characters in the map are valid and stores
the map in a double pointer */
t_map	check_characters(t_map map, int length)
{
	char	*line;
	char	*all_lines;
	char	*temp;

	line = get_next_line(map.file);
	if (line == NULL)
		ft_error("Empty line\n");
	all_lines = ft_calloc(1, 1);
	map.width = (ft_strlen(line) - 1);
	while (line)
	{
		valid_character(&map, line, length, 0);
		temp = all_lines;
		all_lines = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(map.file);
		length++;
	}
	if (map.start != 1 || map.exit != 1 || map.collectibles < 1)
		ft_error("Invalid number of map components\n");
	map.height = length;
	map.map = ft_split(all_lines, '\n');
	free(all_lines);
	return (map);
}
