/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:09:27 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/10 21:49:34 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;

	print_directory();
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			printf("\n");
			break ;
		}
		if (input[0] != '\0')
			add_history(input);
		free(input);
	}
}
