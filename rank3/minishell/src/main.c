/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 14:52:11 by fras          #+#    #+#                 */
/*   Updated: 2023/10/25 00:01:25 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*	steps in main:

	prompt <- init_prompt
	tokens <- lexer(prompt)
	data structure <- parse(tokens)
	modified data structure w/ variables <- expand(data)
	error code <- execute(modified data)
	check error code -> continue loop or return.
	
	Temporary skipping all steps and going from prompt -> execute

	Temp execute prototype: void	execute(char *input, char **envp);
	*/

#include "minishell.h"

void	reset_fd(t_exe *executor)
{
	dup2(executor->old_fds[READ], READ);
	dup2(executor->old_fds[WRITE], WRITE);
}

void	leaks(void)
{
	system("leaks -s minishell");
}

int	main(int argc, char **argv, char **envp)
{
	t_exe	executor;

	atexit(leaks);
	if (!proper_start(argc, argv))
		return (EXIT_FAILURE);
	// init_signal_handler();
	init_executor(&executor, envp);
	while (1)
	{
		reset_fd(&executor);
		executor.input = init_prompt("minishell$ ");
		if (!executor.input)
			return (EXIT_SUCCESS);
		temp_parser(&executor, executor.input);
		free(executor.input);
	}
	empty_executor(&executor);
}

bool	proper_start(int argc, char **argv)
{
	if (argc == 1 && *argv)
		return (true);
	return (false);
}
