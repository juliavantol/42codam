/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:40:14 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/15 13:11:49 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* Initialises the map struct */
t_game	init_game(int file, char *filename)
{
	t_map	map;
	t_game	game;
	t_node	*collectibles;

	map.exit = 0;
	map.start = 0;
	map.collectibles = 0;
	map.file_name = filename;
	map.file = file;
	map = check_characters(map);
	game.map = map;
	collectibles = (t_node *) malloc(sizeof(t_node));
	if (!collectibles)
		ft_error("Malloc\n");
	collectibles = NULL;
	game.collectibles = collectibles;
	game.moves = 0;
	check_walls(game, 0, 0);
	return (game);
}

/* Checks if all the characters in the map are valid */
t_map	check_characters(t_map map)
{
	char	*line;
	int		length;

	length = 0;
	line = get_next_line(map.file);
	map.width = (ft_strlen(line) - 1);
	while (line)
	{
		if (if_empty_line(line) == 1)
			ft_error("Invalid map: empty lines\n");
		valid_character(&map, line, length);
		line = get_next_line(map.file);
		length++;
	}
	if (map.start != 1 || map.exit != 1 || map.collectibles < 1)
		ft_error("Invalid map\n");
	map.height = length;
	map.map = fill_map(map);
	return (map);
}

/* Reads the map into a double pointer char */
char	**fill_map(t_map map_data)
{
	char	*line;
	char	**parsed_map;
	char	*all_lines;
	int		map;

	parsed_map = malloc(map_data.height + 1 * sizeof(char *));
	if (!parsed_map)
		ft_error("Malloc error\n");
	all_lines = ft_calloc(1, 1);
	map = open(map_data.file_name, O_RDONLY);
	if (map < 0)
		ft_error("File couldn't be found\n");
	line = get_next_line(map);
	while (line)
	{
		all_lines = ft_strjoin(all_lines, line);
		line = get_next_line(map);
	}
	parsed_map = ft_split(all_lines, '\n');
	return (parsed_map);
}
