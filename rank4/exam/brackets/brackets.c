#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int len = 0;

	while(str[len])
		len++;
	return(len);
}

void	print_msg(char *str)
{
	write(1, str, ft_strlen(str));
}

void	print_stack(char *stack)
{
	for (int i = 0; i < ft_strlen(stack); i++)
		printf("%c\n", stack[i]);
}

void	check_argument(char *str)
{
	int		max_len = ft_strlen(str) + 1;
	char	stack[max_len];
	int		size = 0;
	int		i = 0;

	stack[0] = '\0';
	while (str[i])
	{
		if (str[i] == '[' || str[i] == '{' || str[i] == '(')
			stack[size++] = str[i];
		else if (str[i] == ']' || str[i] == '}' || str[i] == ')')
		{
			if (size > 0)
			{
				if ((stack[size - 1] == '[' && str[i] == ']') ||
					(stack[size - 1] == '{' && str[i] == '}') ||
					(stack[size - 1] == '(' && str[i] == ')'))
				stack[size - 1] = '\0';
				size--;
			}
			else
			{
				print_msg("KO\n");
				return ;
			}
		}
		i++;
	}
	print_stack(stack);
	if (size == 0)
		print_msg("OK\n");
	else
		print_msg("KO\n");
}

int main(int argc, char **argv)
{
	int i = 1;

	if (argc < 2)
	{
		print_msg("\n");
		return (0);
	}
	while (argv[i])
	{
		check_argument(argv[i]);
		i++;
	}

}
