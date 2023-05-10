/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:34:16 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/10 17:37:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	free_map(char	**map, int height)
{
	int	index;

	index = 0;
	while (index < height - 1)
	{
		printf("%s\n", map[index]);
		free(map[index]);
		index++;
	}
	free(map);
}

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

// int	close_window(t_game game)
// {
// 	// free_map(game.map.map, game.map.height);
// 	free_collectibles(&game.collectibles);
// 	exit(1);
// }

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str != NULL)
		ft_putstr_fd(str, 2);
	exit (1);
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

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
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

void	print_list(t_node **collectibles)
{
	t_node	*head;
	int		count;

	head = *collectibles;
	count = 0;
	while (head != NULL)
	{
		head = head -> next;
		count++;
	}
	printf("%d\n", count);
}
