/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/05 14:28:14 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ARG="grep a"; ./pipex "input.txt" ls $ARG "output.txt"
int	loop_args(t_pipex *pipex, char **argv, int argc)
{
	int		index;

	index = 2;
	while (index < argc - 2)
	{
		pipex->cmd = argv[index];
		pipex->cmd_split = ft_split_args(argv[index]);
		pipes(*pipex);
		free_cmd_split(pipex);
		index++;
	}
	pipex->cmd = argv[index];
	pipex->cmd_split = ft_split_args(argv[index]);
	output(argv[argc - 1], argv[index], *pipex);
	return (0);
}

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	t_pipex	pipex;

	check_input(argv, argc);
	pipex.infile = open(argv[1], O_RDONLY);
	dup2(pipex.infile, 0);
	get_envp(&pipex, envp);
	loop_args(&pipex, argv, argc);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
