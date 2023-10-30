/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 12:52:09 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/30 13:12:51 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map(char *map_path)
{
	char	*line;
	int		map_file;

	map_file = open(map_path, O_RDONLY);
	if (map_file < 0)
		ft_error("Unable to open file", true);
	line = get_next_line(map_file);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(map_file);
	}
	close(map_file);
}
