/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validity.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 19:10:07 by Julia         #+#    #+#                 */
/*   Updated: 2023/05/05 17:48:48 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	valid_character(char *line, int *start, int *exit, int *collectible)
{
	int		index;

	index = 0;
	if (if_empty_line(line) == 1)
		ft_error("Invalid map: empty lines\n");
	while (line[index])
	{
		if (line[index] == 'P')
			(*start)++;
		else if (line[index] == 'C')
			(*collectible)++;
		else if (line[index] == 'E')
			(*exit)++;
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

char	**fill_map(char	*file, int rows)
{
	char	*line;
	char 	**parsed_map;
	int		map;
	
	parsed_map = ft_calloc(rows + 1, sizeof(char));
	if (!parsed_map)
		ft_error("Malloc error\n");
	map = open(file, O_RDONLY);
	if (map < 0)
		ft_error("Invalid file\n");
	line = get_next_line(map);
	rows = 0;
	while (line)
	{
		parsed_map[rows] = line;
		line = get_next_line(map);
		rows++;
	}
	parsed_map[rows] = NULL;
	return (parsed_map);
}

int	check_map(int map, int start, int exit, int collectible)
{
	char	*line;
	int		length;

	length = 0;
	line = get_next_line(map);
	while (line)
	{
		valid_character(line, &start, &exit, &collectible);
		line = get_next_line(map);
		length++;
	}
	if (start != 1 || exit != 1 || collectible < 1)
		ft_error("Invalid map: invalid components\n");
	return (length);
}

