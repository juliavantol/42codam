/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validity.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 19:10:07 by Julia         #+#    #+#                 */
/*   Updated: 2023/05/12 13:04:46 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
			ft_error("Invalid map: illegal components\n");
		index++;
	}
}

void	check_map_walls(char *line)
{
	int		index;

	index = 0;
	while (line[index])
	{
		index++;
	}
}

char	**fill_map(t_map map_data)
{
	char	*line;
	char	**parsed_map;
	char	*all_lines;
	int		map;

	parsed_map = malloc(map_data.height + 1 * sizeof(char *));
	all_lines = ft_calloc(1, 1);
	if (!parsed_map)
		ft_error("Malloc error\n");
	map = open(map_data.file, O_RDONLY);
	if (map < 0)
		ft_error("Invalid file\n");
	line = get_next_line(map);
	while (line)
	{
		all_lines = ft_strjoin(all_lines, line);
		line = get_next_line(map);
	}
	parsed_map = ft_split(all_lines, '\n');
	return (parsed_map);
}

t_map	check_map(int map)
{
	t_map	map_data;
	char	*line;
	int		length;

	length = 0;
	line = get_next_line(map);
	map_data.width = (ft_strlen(line) - 1);
	map_data.exit = 0;
	map_data.start = 0;
	map_data.collectibles = 0;
	while (line)
	{
		if (if_empty_line(line) == 1)
			ft_error("Invalid map: empty lines\n");
		valid_character(&map_data, line, length);
		line = get_next_line(map);
		length++;
	}
	if (map_data.start != 1 || map_data.exit != 1 || map_data.collectibles < 1)
		ft_error("Invalid map\n");
	map_data.height = length;
	return (map_data);
}
