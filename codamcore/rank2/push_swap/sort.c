/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 17:13:57 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/06 18:18:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//make && ./push_swap "87 -487 781 -100 101 0 1"

void	ft_sort(t_node **stack, int	max_len)
{
	stack = NULL;
	printf("max: %d\n", max_len);
	printf("%d\n", 123 >> 10);
}

// /* Creates a new node */
// t_value	*ft_make_value(int num)
// {
// 	t_node	*node;

// 	node = malloc(sizeof(t_node));
// 	if (node == NULL)
// 		return (NULL);
// 	node -> value = num;
// 	node -> next = NULL;
// 	return (node);
// }

void	ft_simplify(char **input, int arg_len, t_node **stack)
{

	int		index;
	int		temp_arr[arg_len][2];
	int		temp;
	int		temp2;
	int		j;
	index = 0;
	while (index < arg_len)
	{
		temp_arr[index][0] = ft_atoi(input[index]);
		temp_arr[index][1] = index;
		index++;
	}
	index = 1;
	while (index < arg_len)
	{
		j = index;
		while (j > 0 && temp_arr[j][0] < temp_arr[j - 1][0])
		{
			temp = temp_arr[j][0];
			temp2 = temp_arr[j][1];
			temp_arr[j][0] = temp_arr[j - 1][0];
			temp_arr[j][1] = temp_arr[j - 1][1];
			temp_arr[j - 1][0] = temp;
			temp_arr[j - 1][1] = temp2;
			j--;
		}
		index++;
	}

	index = 0;
	while (index < arg_len)
		ft_add_node(stack, ft_make_node(temp_arr[index++][1]));
}