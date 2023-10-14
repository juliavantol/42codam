/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   00_executor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 18:44:30 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/14 14:03:35 by Julia         ########   odam.nl         */
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

void	handle_last_command(t_exe *executor, t_cmd *command)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		redirect_output(command);
		run_command(executor, command);
		exit(EXIT_SUCCESS);
	}
	else
	{
		dup2(executor->old_fds[WRITE], WRITE);
		waitpid(pid, &executor->exit_status, 0);
	}	
}

void	handle_command(t_exe *executor, t_cmd *command)
{
	pid_t	pid;

	if (pipe(executor->fds) < 0)
		error_exit("Error with opening the pipe");
	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		redirect_output(command);
		close(executor->fds[READ]);
		dup2(executor->fds[WRITE], WRITE);
		run_command(executor, command);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &executor->exit_status, 0);
		close(executor->fds[WRITE]);
		dup2(executor->fds[READ], READ);
	}
}

void	start_executor(t_exe *executor)
{
	while (executor->index < executor->command_count)
	{
		if (executor->index < executor->command_count - 1)
			handle_command(executor, executor->all_commands[executor->index]);
		else
			handle_last_command(executor, executor->all_commands[executor->index]);
		(executor->index)++;
	}
}
