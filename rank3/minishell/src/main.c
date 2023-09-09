/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 03:00:58 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/09 03:08:01 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline("Minishell> ");
		if (!input)
		{
			printf("\n");
			break ;
		}
		if (input[0] != '\0')
			add_history(input);
		printf("%s\n", input);
		free(input);
	}
}
