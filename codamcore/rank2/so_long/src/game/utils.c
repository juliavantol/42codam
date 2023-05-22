/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:34:16 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/22 16:20:55 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_collectibles(t_node **collectibles)
{
	t_node	*temp;

	if (!collectibles)
		return ;
	while (*collectibles)
	{
		temp = (*collectibles)->next;
		free(*collectibles);
		*collectibles = temp;
	}
	*collectibles = NULL;
	free(collectibles);
}

int	close_window(void)
{
	exit(EXIT_SUCCESS);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str != NULL)
		ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	if_empty_line(char *str)
{
	int		index;
	size_t	empty;

	index = 0;
	empty = 0;
	if (str[0] == '\n' && ft_strlen(str) == 1)
		return (1);
	while (str[index])
	{
		if (str[index] == ' ')
			empty++;
		index++;
	}
	if (empty == ft_strlen(str))
		return (1);
	return (0);
}

void	stop_game(t_game *game)
{
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}

void	print_map(char **map)
{
	int	i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}