// typedef struct s_cmd
// {
// 	char	*command;
// 	bool	output_redirection;
// 	int		*input_fds;
// 	int		*output_fds;
// }	t_cmd;

// typedef struct s_exe
// {
// 	char			**commands;
// 	struct s_cmd	**all_commands;
// 	int				command_count;
// 	int				prev_pipe;
// 	int				infile;
// 	int				*pids;
// 	int				index;
// 	int				fd_in;
// 	int				fd_out;
// 	int				*output_fds;
// 	int				*input_fds;
// 	int				**pipes;
// 	char			**envp;
// 	char			**paths;
// 	char			**minishell_envp;
// }	t_exe;

// void	open_output_fd(t_cmd *cmd_node, char **files, int j)
// {
// 	char	*filename;
// 	int		index;

// 	index = 0;
// 	while (files[j])
// 	{
// 		cmd_node->output_redirection = true;
// 		filename = ft_split(files[j], ' ')[0];
// 		cmd_node->output_fds[index] = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 		free(filename);
// 		index++;
// 		j++;
// 	}
// 	cmd_node->output_fds[index] = '\0';
// }

// void	check_output_redirections(t_exe *executor, t_cmd *command)
// {
// 	int	index;

// 	index = 0;
// 	executor->fd_out = STDOUT_FILENO;
// 	while (command->output_fds[index])
// 	{
// 		executor->fd_out = command->output_fds[index];
// 		index++;
// 	}
// }

// void	run_command(t_exe *executor, t_cmd *command)
// {
// 	char	*path;
// 	char	**cmd;

// 	cmd = ft_split(command->command, ' ');
// 	path = get_cmd_path(executor->paths, cmd[0]);
// 	if (!path)
// 		error_exit("Command not found");
// 	if (execve(path, cmd, executor->minishell_envp) == -1)
// 		error_exit("Execve error");
// }

// void	handle_command(t_exe *executor, t_cmd *command, int *fds)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid < 0)
// 		ft_error("Error with fork", errno);
// 	if (pid == 0)
// 	{
// 		if (executor->fd_in != STDIN_FILENO)
// 		{
// 			dup2(executor->fd_in, STDIN_FILENO);
// 			close(executor->fd_in);
// 		}
// 		if (executor->fd_out != STDOUT_FILENO)
//         {
// 			dup2(executor->fd_out, STDOUT_FILENO);
//             close(executor->fd_out);
//         }
// 		dup2(fds[WRITE], STDOUT_FILENO);
// 		run_command(executor, command);
// 		exit(EXIT_SUCCESS);
// 	}
// }

// void	start_executor(t_exe *executor)
// {
// 	int fds[2];
// 	int status;
// 	int	index;
	
// 	executor->fd_in = STDIN_FILENO;
// 	while (executor->index < executor->command_count - 1)
// 	{
// 		if (pipe(fds) < 0)
// 			error_exit("Error with opening the pipe");
// 		executor->fd_out = fds[WRITE];
// 		check_output_redirections(executor, executor->all_commands[executor->index]);
// 		handle_command(executor, executor->all_commands[executor->index], fds);
// 		close(fds[WRITE]);
// 		executor->fd_in = fds[READ];
// 		(executor->index)++;
// 	}
// 	executor->fd_out = STDOUT_FILENO;
// 	check_output_redirections(executor, executor->all_commands[executor->index]);
// 	handle_command(executor, executor->all_commands[executor->index], fds);
// 	index = 0;
// 	while (index < executor->command_count)
// 	{
// 		wait(&status);
// 		index++;
// 	}
// }