/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 15:36:02 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/04/17 18:35:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks push_swap");
}

t_stack2 *swap(t_stack2 * ptr1, t_stack2 * ptr2)
{
   	t_stack2 *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void	bubbleSort(t_stack2 **stack, int count)
{
	t_stack2 **head;
	int swapped;
    int i;
	int j; 

	i = 0;
	while (i <= count)
	{
		head = stack;
		swapped = 0;
		j = 0;
		while (j < count - i - 1)
		{
			if ((*head)-> value > (*head) -> next -> value)
			{
				*head = swap(*head, (*head)-> next);
				// temp = (*head) -> next -> next;
				// (*head) -> next -> next = (*head);
				// (*head) -> next = temp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
    // for (i = 0; i <= count; i++) {
  
    //     head = stack;
    //     swapped = 0;
  
    //     for (j = 0; j < count - i - 1; j++) {
    //         t_stack2 * p1 = *head;
    //         t_stack2 * p2 = p1->next;
    //         if (p1->value > p2->value) {

    //             *head = swap(p1, p2);
    //             swapped = 1;
    //         }
  
    //         head = &(*head)->next;
    //     }
    //     if (swapped == 0)
    //         break;
    // }
}

// static void	insertion_sort_stack(t_stack2 **stack, int arg_len)
// {
// 	t_stack2	*node;
// 	t_stack2	*temp;
// 	t_stack2	*temp_node;

// 	node = *stack;
// 	while (node)
// 	{
// 		temp = node;
// 		while (temp)
// 		{
// 			if (temp -> value > temp -> next -> value)
// 			{
// 				temp_node = temp;
// 				temp = temp -> next;
// 				temp -> next = temp_node;
// 			}
// 			exit(1);
// 			temp = temp -> next;
// 		}
// 		node = node -> next;
// 	}
// 	arg_len--;
// 	// index = 0;
// 	// while (index < arg_len)
// 	// {
// 	// 	stack[index].new_position = index;
// 	// 	index++;
// 	// }
// }

void	fill_temp(t_stack2 **stack, char *value, int index)
{
	int			num;
	t_stack2	*node;

	num = ft_atoi(value);
	node = new_node(num, index);
	add_node(stack, node);
}

void	parse_input(char	**argv, int count, int index)
{
	char		**temp;
	t_stack2	**temp_stack;

	temp_stack = (t_stack2 **)malloc(sizeof(t_stack2));
	if (!temp_stack)
		exit(1);
	*temp_stack = NULL;
	argv++;
	while (*argv)
	{
		if (ft_strchr(*argv, ' '))
		{
			temp = ft_split(*argv, ' ');
			index = 0;
			while (temp[index])
				fill_temp(temp_stack, temp[index++], count++);
		}
		else
			fill_temp(temp_stack, *argv, count++);
		argv++;
	}
	// print_stack2(*temp_stack, count);
	// printf("\n\n");
	bubbleSort(temp_stack, count);
	print_stack2(*temp_stack, count);
}