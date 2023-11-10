/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 18:44:30 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/10 17:18:34 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	run_command(t_exe *executor, t_cmd *command)
{
	char	*path;
	char	**envp;
	char	**cmd;

	if (ft_strcmp(command->command_name, "exit") == true)
		exit_shell(executor, EXIT_SUCCESS, command);
	envp = convert_envp_to_char(executor);
	cmd = ft_split(command->command_name, ' ');
	path = get_cmd_path(executor, cmd[0], envp, 0);
	if (!path)
		error_exit("Command not found");
	restore_signals();
	if (execve(path, cmd, envp) == -1)
		error_exit("Execve error");
}

void	wait_for_all_child_processes(t_exe *executor)
{
	int	index;
	int	status;

	index = 0;
	while (executor->pids[index])
		waitpid(executor->pids[index++], &status, 0);
}

void	single_command(t_exe *executor, t_cmd *command)
{
	int	status;

	if (ft_strcmp(command->split[0], "exit") == true)
		exit_shell(executor, EXIT_SUCCESS, command);
	executor->pids[executor->index] = fork();
	if (executor->pids[executor->index] == 0)
	{
		redirect_input(command);
		redirect_output(command);
		if (check_builtin(executor, command))
			return ;
		run_command(executor, command);
	}
	waitpid(executor->pids[executor->index], &status, 0);
}

void	ft_fork(t_exe *executor, int fd_in, int end[2], t_cmd *command)
{
	executor->pids[executor->index] = fork();
	if (executor->pids[executor->index] == 0)
	{
		redirect_input(command);
		redirect_output(command);
		dup2(fd_in, STDIN_FILENO);
		close(end[0]);
		dup2(end[1], STDOUT_FILENO);
		close(end[1]);
		if (executor->index > 0)
			close(fd_in);
		if (check_builtin(executor, command))
			return ;
		run_command(executor, command);
	}
}

void	start_executor(t_exe *executor)
{
	t_cmd	*head;
	int		end[2];
	int		fd_in;

	head = executor->commands_list;
	handle_heredocs(executor);
	if (executor->command_count == 1)
		single_command(executor, head);
	else
	{
		fd_in = STDIN_FILENO;
		while (head != NULL)
		{
			if (head->next)
				pipe(end);
			ft_fork(executor, fd_in, end, head);
			close(end[1]);
			if (executor->index > 0)
				close(fd_in);
			fd_in = end[0];
			head = head->next;
			(executor->index)++;
		}
	}
	executor->pids[executor->index] = '\0';
	wait_for_all_child_processes(executor);
}
