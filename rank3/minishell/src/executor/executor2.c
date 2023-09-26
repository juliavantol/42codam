/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/26 12:31:29 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

// void	run_command(t_exe *executor, char **split_cmd)
// {
// 	char	*path;

// 	path = get_cmd_path(executor->paths, split_cmd[0]);
// 	if (!path)
// 		error_exit("Command not found");
// 	if (execve(path, split_cmd, executor->minishell_envp) == -1)
// 	{
// 		error_exit("Execve error");
// 	}
// }

// void	start_pipe(t_exe *executor, char **cmd)
// {
// 	int		fds[2];
// 	pid_t	pid;

// 	if (pipe(fds) < 0)
// 		error_exit("Error with opening the pipe");
// 	pid = fork();
// 	if (pid < 0)
// 		error_exit("Error with fork");
// 	if (pid == 0)
// 	{
// 		if (executor->infile < 0)
// 		{
// 			ft_putstr_fd("input: No such file or directory\n", 2);
// 			exit(0);
// 		}
// 		close(fds[0]);
// 		dup2(fds[1], 1);
// 		if (cmd != NULL)
// 			run_command(executor, cmd);
// 	}
// 	else
// 	{
// 		close(fds[1]);
// 		dup2(fds[0], 0);
// 	}
// }

// void	execute2(t_exe *executor, char *str)
// {
// 	char	**commands;
// 	char	**cmd;
// 	int		index;

// 	index = 0;
// 	commands = ft_split(str, '|');
// 	while (commands[index])
// 	{
// 		cmd = ft_split(commands[index], ' ');
// 		start_pipe(executor, cmd);
// 		empty_array(cmd);
// 		index++;
// 	}
// 	empty_array(commands);
// }

