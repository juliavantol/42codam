/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 15:36:02 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/14 14:31:24 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks push_swap");
}

/* Checks if there are only digits in the string */
int	ft_digit_str(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) == 0 && str[i] != '-' && str[i] != '+')
			|| ((str[i] == '-' || str[i] == '+') && i != 0))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (1);
}

/* Checks whether the input only contains digits */
char	**check_input(int argc, char	**argv, int	*arg_len)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		while (args[(*arg_len)])
			ft_digit_str(args[(*arg_len)++]);
		return (args);
	}
	else
	{
		(*arg_len)++;
		while (argv[(*arg_len)])
			ft_digit_str(argv[(*arg_len)++]);
		(*arg_len)--;
		return (&argv[1]);
	}
	return (NULL);
}

void	add_to_nums(char **input)
{
	int		index;
	int		size;
	t_value	*indexed_nums;
	t_value	*temp;

	size = 0;
	while (input[size])
		size++;
	indexed_nums = malloc((size + 1) * sizeof(t_value));
	if (!indexed_nums)
		exit(1);
	index = 0;
	while (index < size)
	{
		temp = malloc(sizeof(t_value));
		if (!temp)
			exit(1);
		temp -> value = ft_atoi(input[index]);
		temp -> original_position = index;
		indexed_nums[index] = *temp;
		index++;
		free(temp);
	}
}

char	**ft_array_join(char **arr, char *str)
{
	char	**new_arr;
	int		size;

	size = 0;
	ft_digit_str(str);
	if (arr == NULL)
	{
		new_arr = malloc(1 * sizeof(char *));
		new_arr[0] = str;
		new_arr[1] = NULL;
	}
	else
	{
		while (arr[size])
			size++;
		new_arr = malloc((size + 2) * sizeof(char *));
		size = 0;
		while (arr[size])
		{
			new_arr[size] = arr[size];
			size++;
		}
		new_arr[size] = str;
		new_arr[++size] = NULL;
	}
	free(arr);
	return (new_arr);
}

char	**parse_input(char	**argv)
{
	char	**temp;
	char	**input;
	int		index;

	input = NULL;
	argv++;
	while (*argv)
	{
		if (ft_strchr(*argv, ' '))
		{
			temp = ft_split(*argv, ' ');
			index = 0;
			while (temp[index])
				input = ft_array_join(input, temp[index++]);
		}
		else
			input = ft_array_join(input, *argv);
		argv++;
	}
	add_to_nums(input);
	return (input);
}