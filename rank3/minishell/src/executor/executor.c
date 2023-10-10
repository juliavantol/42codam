/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/10 02:46:51 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	run_command(t_exe *executor, t_cmd *command)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(command->command, ' ');
	path = get_cmd_path(executor->paths, cmd[0]);
	if (!path)
		error_exit("Command not found");
	if (execve(path, cmd, executor->minishell_envp) == -1)
		error_exit("Execve error");
}

void	handle_command(t_exe *executor, t_cmd *command, int *fds)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_error("Error with fork", errno);
	check_output_redirections(executor, command);
	if (pid == 0)
	{
		if (executor->fd_in != STDIN_FILENO)
		{
			dup2(executor->fd_in, STDIN_FILENO);
			close(executor->fd_in);
		}
		if (executor->fd_out != STDOUT_FILENO)
        {
			dup2(executor->fd_out, STDOUT_FILENO);
            close(executor->fd_out);
        }
        dup2(fds[WRITE], STDOUT_FILENO);
        close(fds[WRITE]);
		run_command(executor, command);
		exit(EXIT_SUCCESS);
	}
}

void	start_executor(t_exe *executor)
{
	int fds[2];
	int status;
	int	index;
	
	executor->fd_in = STDIN_FILENO;
	while (executor->index < executor->command_count - 1)
	{
		if (pipe(fds) < 0)
			error_exit("Error with opening the pipe");
		executor->fd_out = fds[WRITE];
		handle_command(executor, executor->all_commands[executor->index], fds);
		close(fds[WRITE]);
		executor->fd_in = fds[READ];
		(executor->index)++;
	}
	executor->fd_out = STDOUT_FILENO;
	handle_command(executor, executor->all_commands[executor->index], fds);
	index = 0;
	while (index < executor->command_count)
	{
		wait(&status);
		index++;
	}
}
