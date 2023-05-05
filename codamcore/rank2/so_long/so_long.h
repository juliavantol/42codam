/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:30:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/06 01:47:21 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "include/libft/libft.h"
# include "include/get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

# define PIXELS 16

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	*file;
	char	**map;
	int		width;
	int		height;
}	t_map;

void	ft_error(char *str);
int		check_map(int map, int start, int exit, int collectible);
int		if_empty_line(char *str);
void	open_window(t_map map_data);
char	**fill_map(t_map map_data);
void	print_map(char	**map);

#endif