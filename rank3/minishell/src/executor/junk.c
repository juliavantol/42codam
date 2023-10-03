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

// void	execute_multiple_command(t_exe *executor, char **cmd, int index)
// {
// 	int		fds[2];
// 	int		status;
// 	int		i;
// 	pid_t	pid;

// 	if (index < (executor->command_count - 1))
// 		pipe(fds);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		if (index > 0)
// 		{
// 			dup2(executor->pipes[index - 1][0], INPUT);
// 			close(executor->pipes[index - 1][0]);
// 			close(executor->pipes[index - 1][1]);
// 		}
// 		else
// 		{
// 			close(executor->pipes[0][0]);
// 			close(executor->pipes[0][1]);
// 		}
// 		if (index < (executor->command_count - 1))
// 		{
// 			dup2(fds[WRITE], OUTPUT);
// 			close(fds[READ]);
// 			close(fds[WRITE]);
// 		}
// 		else
// 		{
// 			// dup2(fds[READ], INPUT);
// 			close(fds[READ]);
// 			// close(fds[WRITE]);
// 		}
// 		i = 0;
// 		while (i < (executor->command_count - 1))
// 		{
// 			if (i != index - 1)
// 			{
// 				close(executor->pipes[i][0]);
// 				close(executor->pipes[i][1]);
// 			}
// 			i++;
// 		}
// 		run_command(executor, cmd);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		if (index > 0)
// 		{
// 			close(executor->pipes[index - 1][0]);
// 			close(executor->pipes[index - 1][1]);
// 		}
// 		if (index < (executor->command_count - 1))
// 		{
// 			executor->pipes[index][0] = fds[0];
// 			executor->pipes[index][1] = fds[1];
// 		}
// 		else
// 			close(fds[WRITE]);
// 		waitpid(pid, &status, 0);
// 		if (WIFEXITED(status) && WEXITSTATUS(status) != EXIT_SUCCESS)
// 			exit(EXIT_FAILURE);
// 	}
// }

// void	execute_single_command(t_exe *executor)
// {
// 	int		fds[2];
// 	int		status;
// 	char	**cmd;
// 	pid_t	pid;

// 	if (pipe(fds) < 0)
// 		error_exit("Error with opening the pipe");
// 	pid = fork();
// 	if (pid < 0)
// 		error_exit("Error with fork");
// 	if (pid == 0)
// 	{
// 		cmd = ft_split(executor->commands[0], ' ');
// 		run_command(executor, cmd);
// 		empty_array(cmd);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 		waitpid(pid, &status, 0);
// }

// void	start_executor(t_exe *executor)
// {
// 	char	**cmd;
// 	int		index;

// 	index = 0;
// 	if (executor->command_count == 1)
// 		execute_single_command(executor);
// 	else
// 	{
// 		executor->pipes = (int **)ft_malloc(sizeof(int *)
// 				* (executor->command_count - 1));
// 		while (index < executor->command_count - 1)
// 			executor->pipes[index++] = ft_malloc(sizeof(int) * 2);
// 		index = 0;
// 		while (executor->commands[index])
// 		{
// 			cmd = ft_split(executor->commands[index], ' ');
// 			execute_multiple_command(executor, cmd, index);
// 			empty_array(cmd);
// 			index++;
// 		}
// 	}
// }