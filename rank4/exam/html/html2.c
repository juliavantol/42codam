#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// gcc -Wall -Wextra -Werror -fsanitize=address html.c -o html

int	ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

void	print_msg(char *str)
{
	write(1, str, ft_strlen(str));
}

void	free_stack(char **stack, int size)
{
	for (int i = 0; i < size; i++)
		free(stack[i]);
	free(stack);
}

char	*ft_strdup(char *str)
{
	char	*output = NULL;
	int 	len = ft_strlen(str) + 1;
	int		i = 0;

	output = malloc(len * sizeof(char));
	if (!output)
		return (NULL);
	while (str[i])
	{
		output[i] = str[i];
		i++;
	}
	output[i] = '\0';
	return (output);

}

void	add_to_stack(char ***stack, int *size, char *tag)
{
	char	**new_stack = malloc((*size + 2) * sizeof(char *));
	if (!new_stack)
		return ;
	for (int i = 0; i < *size; i++)
		new_stack[i] = (*stack)[i];
	new_stack[*size] = ft_strdup(tag);
	new_stack[*size + 1] = NULL;
	if (*stack)
		free(*stack);
	*stack = new_stack;
	(*size)++;
	
}

void	pop_stack(char ***stack, int *size)
{
	int	last = 0;

	while ((*stack)[last + 1])
		last++;
	free((*stack)[last]);
	(*stack)[last] = NULL;
	(*size)--;
}

int main(int argc, char **argv)
{
	char	*input;
	char	**stack = NULL;
	int		size = 0;
	int		start_tag = 0;
	char	*buffer = NULL;
	int		len_tag = 0;
	int		i = 0;

	if (argc != 2)
		return (0);
	input = argv[1];
	while (input[i])
	{
		if (input[i] == '<')
		{
			start_tag = i + 1;
			len_tag = 0;
			while (input[i] && input[i + 1] != '>')
			{
				i++;
				len_tag++;
			}
			if (len_tag == 0)
			{
				i++;
				continue;
			}
			buffer = malloc(len_tag + 1);
			strncpy(buffer, input + start_tag, len_tag);
			buffer[len_tag] = '\0';
			if (buffer[0] == '/')
			{
				if (size < 1)
				{
					print_msg("KO\n");
					break;
				}
				if (strncmp(stack[size - 1], buffer + 1, len_tag) == 0)
					pop_stack(&stack, &size);
				free(buffer);
			}
			else
			{
				if (strncmp("img ", buffer, 4) == 0)
				{
					while (input[i] && input[i] != '>')
						i++;
					if (input[i] != '>')
					{
						add_to_stack(&stack, &size, buffer);
						free(buffer);
						break;
					}
				}
				else
					add_to_stack(&stack, &size, buffer);
				free(buffer);
			}
		}
		else
			i++;
	}
	if (size == 0)
		print_msg("OK\n");
	else
		print_msg("KO\n");
	free_stack(stack, size);
}
