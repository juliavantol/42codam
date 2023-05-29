/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 14:11:26 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/29 23:54:20 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*animate_down(t_game *game)
{
	char		*path;

	path = NULL;
	if (game->loop == 1)
		path = "textures/grandma/down1.png";
	else if (game->loop == 2)
		path = "textures/grandma/down2.png";
	else if (game->loop == 3)
		path = "textures/grandma/down3.png";
	return (path);
}

char	*animate_up(t_game *game)
{
	char		*path;

	path = NULL;
	if (game->loop == 1)
		path = "textures/grandma/up1.png";
	else if (game->loop == 2)
		path = "textures/grandma/up2.png";
	else if (game->loop == 3)
		path = "textures/grandma/up3.png";
	return (path);
}

char	*animate_left(t_game *game)
{
	char		*path;

	path = NULL;
	if (game->loop == 1)
		path = "textures/grandma/left1.png";
	else if (game->loop == 2)
		path = "textures/grandma/left2.png";
	else if (game->loop == 3)
		path = "textures/grandma/left3.png";
	return (path);
}

char	*animate_right(t_game *game)
{
	char		*path;

	path = NULL;
	if (game->loop == 1)
		path = "textures/grandma/right1.png";
	else if (game->loop == 2)
		path = "textures/grandma/right2.png";
	else if (game->loop == 3)
		path = "textures/grandma/right3.png";
	return (path);
}

/* Loops through displaying the player image in the current direction */
void	animate_player(t_game *game, char *path, int x, int y)
{
	mlx_image_t	*temp;

	if (game->loop < 3)
		game->loop += 1;
	else
		game->loop = 1;
	if (game->direction == 'd')
		path = animate_down(game);
	else if (game->direction == 'u')
		path = animate_up(game);
	else if (game->direction == 'l')
		path = animate_left(game);
	else if (game->direction == 'r')
		path = animate_right(game);
	if (path != NULL)
	{
		temp = get_picture(game->mlx, path);
		mlx_delete_image(game->mlx, game->player_img);
		put_image(game->mlx, temp, x, y);
		game->player_img = temp;
		game->player_img->instances[0].x = x;
		game->player_img->instances[0].y = y;
	}
}
