/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 16:31:44 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/13 14:19:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	char	*stdin;
	char	*stdout;
	char	*cmd1;
	char	*cmd2;
	int		len;

	if (argc == 5)
	{
		stdin = argv[1];
		cmd1 = argv[2];
		stdout = argv[3];
		cmd2 = argv[4];
		printf("%s %s %s %s\n", stdin, cmd1, stdout, cmd2);
	}
	else
	{
		len = ft_strlen("he!");
		printf("%d\n", len);
		return 0;
	}
}
