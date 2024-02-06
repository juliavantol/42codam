#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// gcc -Wall -Wextra -Werror -fsanitize=address html3.c -o html && ./html 

int ft_strlen(char *str)
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

void	empty_stack(char **stack, int size)
{
	for (int i = 0; i < size; i++)
		free(stack[i]);
	free(stack);
}

void	print_stack(char **stack, int size)
{
	printf("-------STACK-------\n");
	for (int i = 0; i < size; i++)
		printf("%s\n", stack[i]);
}

char	*ft_strdup(char *str)
{
	int i = 0;
	int len = ft_strlen(str) + 1;
	char *output = malloc(len * sizeof(char));

	while (str[i])
	{
		output[i] = str[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

void	add_to_stack(char ***stack, int *size, char *str)
{
	char **new_stack = malloc((*size + 2) * sizeof(char *));
	if (!new_stack)
		return;
	for (int i = 0; i < *size; i++)
		new_stack[i] = (*stack)[i];
	new_stack[*size] = ft_strdup(str);
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
	char	*str;
	char	**stack = NULL;
	char	*buffer = NULL;
	int		start_tag;
	int		len_tag;
	int		i = 0;
	int		size = 0;

	if (argc != 2)
	{
		print_msg("\n");
		return (0);
	}
	str = argv[1];
	while (str[i])
	{
		if (str[i] == '<')
		{
			start_tag = ++i;
			len_tag = 0;
			while (str[i] && str[i] != '>')
			{
				len_tag++;
				i++;
			}
			buffer = malloc((len_tag + 1) * sizeof(char));
			strncpy(buffer, str + start_tag, len_tag);
			buffer[len_tag] = '\0';
			if (buffer[0] == '/')
			{
				if (size > 0)
				{
					if (strncmp(stack[size - 1], buffer + 1, len_tag) == 0)
						pop_stack(&stack, &size);
					else
					{
						add_to_stack(&stack, &size, buffer);
						break ;
					}

				}
				else
				{
					add_to_stack(&stack, &size, buffer);
					break ;
				}
			}
			else
			{
				if (strncmp("img ", buffer, 4) == 0)
				{
					while (str[i] && str[i] != '>')
						i++;
					if (str[i] != '>')
					{
						add_to_stack(&stack, &size, buffer);
						break ;
					}
					else
						i++;

				}
				else
					add_to_stack(&stack, &size, buffer);
			}
			free(buffer);
		}
		else
			i++;
	}
	if (stack[0] != NULL)
		print_msg("KO\n");
	else
		print_msg("OK\n");
	empty_stack(stack, size);
}
