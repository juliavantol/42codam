/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:30:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/27 20:02:09 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "include/libft/libft.h"
# include "include/get_next_line/get_next_line.h"

void	ft_error(char *str);
void	check_map_dups(int map, int start, int exit, int collectible);
int		if_empty_line(char *str);

#endif