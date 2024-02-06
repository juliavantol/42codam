#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// gcc -Wall -Wextra -Werror -fsanitize=address html.c -o html && ./html "<b>hallo</b>"

int ft_strlen(char *str)
{
    int len = 0;
    while(str[len])
        len++;
    return (len);
}

char	*ft_strdup(char *s)
{
	char	*new;
	int		index;

	index = 0;
	while (s[index] != '\0')
		index++;
	new = malloc(index + 1);
	if (new == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		new[index] = s[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}

char	*ft_substr(char *s, int start, int len)
{
	int     index;
	char	*sub;

	index = 0;
	if (start >= ft_strlen(s) || ft_strlen(s) == 0)
		return (ft_strdup(""));
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (index < len && s[start] != '\0')
		sub[index++] = s[start++];
	sub[index] = '\0';
	return (sub);
}


void    print_stack(char **stack)
{
    int i = 0;

    printf("\n-------STACK-------\n");
    while (stack[i])
        printf("%s\n", stack[i++]);
    printf("--------------------\n");
}

void    add_to_stack(char ***stack, int *size, char *str)
{
    char    **new_stack = malloc((*size + 2) * sizeof(char *));

    if (!new_stack)
        return ;
    for (int i = 0; i < *size; i++)
        new_stack[i] = (*stack)[i];
    new_stack[*size] = ft_strdup(str);
    new_stack[*size + 1] = NULL;
    if (*stack)
        free(*stack);
    *stack = new_stack;
    (*size)++;

}

void    pop_stack(char ***stack, int *size)
{
    int     last = 0;

    while ((*stack)[last + 1])
        last++;
    free((*stack)[last]);
    (*stack)[last] = NULL;
    (*size)--;

}


int main(int argc, char **argv)
{
    char    **stack = NULL;
    char    *tag;
    int     size = 0;
    int     i = 0;
    int     start_tag = 0;
    int     end_tag = 0;
    int     len = 0;

    if (argc != 2)
        return (0);

    while (argv[1][i])
    {
        if (argv[1][i] == '<')
        {
            start_tag = i + 1;
            end_tag = 0;
            while (argv[1][i] && argv[1][i + 1] != '>')
            {
                i++;
                end_tag++;
            }
            if (argv[1][start_tag] == '/')
            {
                tag = ft_substr(argv[1], start_tag + 1, end_tag - 1);
                len = ft_strlen(tag);
                if (strncmp(stack[size - 1], tag, len) == 0)
                    pop_stack(&stack, &size);
                else
                    break ;
            }
            else
            {
                tag = ft_substr(argv[1], start_tag, end_tag);
                if (strncmp(tag, "img ", 4) == 0)
                {
                    while (argv[1][i] && argv[1][i] != '>')
                        i++;
                    if (argv[1][i] != '>')
                    {
                        printf("KO\n");
                        break ;
                    }
                }
                else
                    add_to_stack(&stack, &size, tag);
            }
            free(tag);
        }
        i++;
    }
    if (stack)
    {
        if (stack[0] == NULL)
            printf("OK\n");
        else
            printf("KO\n");
    }
    for (int j = 0; j < size; j++)
        free(stack[j]);
    free(stack);
}
