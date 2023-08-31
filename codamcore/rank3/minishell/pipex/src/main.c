/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/08/31 15:15:57 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ARG="grep a"; ./pipex "input.txt" ls $ARG "output.txt"

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	t_pipex	pipex;

	if (argc < 5)
	{
		ft_putstr_fd("Not enough arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	pipex.infile = open(argv[1], O_RDONLY);
	dup2(pipex.infile, 0);
	get_envp(&pipex, envp);
	loop_args(&pipex, argv, argc);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
