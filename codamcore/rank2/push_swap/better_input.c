/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   better_input.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:28:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/19 15:35:19 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_temp	*new_temp(char *str, int size)
{
	t_temp	*node;
	
	node = malloc(sizeof(t_temp));
	if (!node)
		exit(1);
	node -> value = ft_atoi_long(str);
	node -> original_position = size;
	return (node);
}

t_temp	*temp_stack(t_temp *stack, char *str, int size)
{
	t_temp	*temp_stack;
	int		index;

	index = 0;
	temp_stack = malloc((size + 2) * sizeof(t_temp));
	if (!temp_stack)
		exit (1);
	if (stack == NULL)
		temp_stack[index] = *(new_temp(str, size));
	else
	{
		while (index < size)
		{
			temp_stack[index] = stack[index];
			index++;
		}
		temp_stack[index] = *(new_temp(str, size));
	}
	if (size != 0)
		free(str);
	return (temp_stack);
}

void	handle_input(char	**argv, int *arg_len)
{
	char	**temp;
	t_temp	*input;

	argv++;
	input = NULL;
	while (*argv)
	{
		if (ft_strchr(*argv, ' '))
		{
			temp = ft_split(*argv, ' ');
			while (*temp)
				input = temp_stack(input, *temp++, (*arg_len)++);
		}
		else
			input = temp_stack(input, *argv, (*arg_len)++);

		argv++;
	}
	check_dups(input, *arg_len);
	// fill_stack(indexed_nums, stack, arg_len);
	
}
