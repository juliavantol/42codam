/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validity.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/27 19:10:07 by Julia         #+#    #+#                 */
/*   Updated: 2023/04/28 10:53:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_dups(char	*line, int *start, int *exit, int *collectible)
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

void	check_map(int map)
{
	char	*line;
	int		start;
	int		exit;
	int		collectible;

	start = 0;
	exit = 0;
	collectible = 0;
	line = get_next_line(map);
	while (line)
	{
		check_map_dups(line, &start, &exit, &collectible);
		line = get_next_line(map);
	}
	if (start != 1 || exit != 1 || collectible < 1)
		ft_error("Invalid map: invalid components\n");
}

