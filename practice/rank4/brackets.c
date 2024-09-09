#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int len = 0;

	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

void	print_msg(char *str)
{
	int len = ft_strlen(str);

	if (str)
		write(1, str, len);
}

bool	if_matching_pair(char opening, char closing)
{
	return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool	if_opening_bracket(char c)
{
	if (c == '(' || c == '[' || c == '{')
		return (true);
	return (false);
}

bool	if_closing_bracket(char c)
{
	if (c == ')' || c == ']' || c ==  '}')
		return (true);
	return (false);
}

void	add_to_stack(char *stack, char c)
{
	int		index = 0;

	while (stack[index])
		index++;
	stack[index++] = c;
	stack[index] = '\0';
}

void	pop_stack(char *stack)
{
	int		index = 0;

	while (stack[index])
		index++;
	stack[index - 1] = '\0';
}

char	show_top_stack(char *stack)
{
	int	index = 0;

	while (stack[index])
		index++;
	if (stack[index - 1])
		return (stack[index - 1]);
	return ('\0');
}

void	check_argument(char *str)
{
	int		size = ft_strlen(str) + 1;
	char	stack[size];
	int		index = 0;

	stack[0] = '\0';
	while (str[index])
	{
		if (if_opening_bracket(str[index]) == true)
			add_to_stack(stack, str[index]);
		else if (if_closing_bracket(str[index]) == true)
		{
			if (if_matching_pair(show_top_stack(stack), str[index]) == true)
				pop_stack(stack);
			else
			{
				print_msg("Error\n");
				return ;
			}
		}
		index++;
	}
	print_msg("OK\n");
}

int main(int argc, char **argv)
{
	int index = 1;

	if (argc < 2)
	{
		print_msg("\n");
		return (0);
	}
	while (argv[index])
	{
		check_argument(argv[index]);
		index++;
	}
}
