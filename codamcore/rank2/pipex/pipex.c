/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:17:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/28 12:42:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	output(char *output, char *cmd, char **paths)
{
	int	output_file;

	output_file = open(output, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (output_file < 0)
		error_exit("File couldn't be opened");
	if (access(output, R_OK) != 0 || access(output, W_OK) != 0)
		error_exit("Can't be read/written");
	dup2(output_file, 1);
	output--;
	run_command(paths, cmd);
}

static void	main_loop(char *cmd, char **paths)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) < 0)
		error_exit("Error with opening the pipe");
	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], 1);
		run_command(paths, cmd);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], 0);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	char			**path;
	struct s_pipex	pipex;
	int				index;
	int				status;

	if (argc < 5)
		error_exit("Not enough arguments");
	path = get_paths(envp);
	index = 2;
	pipex.infile = open(argv[1], O_RDONLY);
	dup2(pipex.infile, 0);
	while (index < argc - 2)
		main_loop(argv[index++], path);
	output(argv[argc - 1], argv[index], path);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
