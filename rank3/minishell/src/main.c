/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 14:52:11 by fras          #+#    #+#                 */
/*   Updated: 2023/11/20 12:34:30 by juvan-to      ########   odam.nl         */
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

int	main(int argc, char **argv, char **envp)
{
	t_exe	executor;

	if (!proper_start(argc, argv))
		return (EXIT_FAILURE);
	init_executor(&executor, envp);
	while (1)
	{
		init_signal_handler();
		executor.input = init_prompt("minishell$ ");
		restore_signals();
		if (!executor.input)
			return (ctrl_d(&executor));
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
