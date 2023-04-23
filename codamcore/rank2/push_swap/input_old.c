/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_old.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 18:21:56 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/23 19:29:16 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_back(t_temp	*input, int arg_len)
{
	int		index;
	int		j;
	t_temp	temp;

	index = 1;
	while (index < arg_len)
	{
		j = index;
		while (j > 0 && input[j].original_position < input[j - 1].original_position)
		{
			temp = input[j];
			input[j] = input[j - 1];
			input[j - 1] = temp;
			j--;
		}
		index++;
	}
}

static void	sort_values(t_temp	*input, int arg_len)
{
	int		index;
	int		j;
	t_temp	temp;

	index = 1;
	while (index < arg_len)
	{
		j = index;
		while (j > 0 && input[j].value < input[j - 1].value)
		{
			temp = input[j];
			input[j] = input[j - 1];
			input[j - 1] = temp;
			j--;
		}
		index++;
	}
	index = 0;
	while (index < arg_len)
	{
		input[index].new_position = index;
		index++;
	}
}

t_temp	new_temp(char *str, int size)
{
	t_temp	node;

	node . value = ft_atoi_long(str);
	node . original_position = size;
	return (node);
}

t_temp	*temp_stack(t_temp *stack, char *str, int size)
{
	t_temp	*temp_stack;
	int		index;

	index = 0;
	ft_digit_str(str);

	temp_stack = malloc((size + 1) * sizeof(t_temp));

	if (!temp_stack)
		exit (1);
	if (stack == NULL)
	{
		temp_stack[index] = (new_temp(str, size));
		// leaks();
}
	else
	{
		while (index < size)
		{
			temp_stack[index] = stack[index];
			index++;
		}
		temp_stack[index] = (new_temp(str, size));
	}

	free(stack);
	return (temp_stack);
}

t_temp	*handle_input(char	**argv, int *arg_len)
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
	
	check_duplicates(input, *arg_len);
	sort_values(input, *arg_len);
	sort_back(input, *arg_len);
	return (input);
}
