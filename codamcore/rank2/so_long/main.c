/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:17:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/28 18:02:13 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system ("leaks so_long");
}

int	main(int argc, char	**argv)
{
	int			file;
	char		*temp;
	t_game		game;

	if (argc != 2)
		ft_error("Not enough arguments\n");
	temp = ft_substr(argv[1], ft_strlen(argv[1] + 4), 4);
	if (ft_strncmp(temp, ".ber", 4) != 0)
		ft_error("File must be a .ber extension\n");
	free(temp);
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		ft_error("File couldn't be opened\n");
	srand(time(NULL));
	game = init_game(file, argv[1]);
	game.mlx = NULL;
	check_path(game.map, &game);
	close(file);
	open_window(game);
	exit(EXIT_SUCCESS);
}
