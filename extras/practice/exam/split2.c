#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	leaks(void)
{
	system("leaks split2");
}

int count(char *str, int c)
{
	int count = 0;
	int i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char *sub(char *str, int start, int end)
{
	char *s = malloc(sizeof(char) * (end - start + 1));
	int i = start;
	int j = 0;

	while (str[i] && i < end)
		s[j++] = str[i++];
	s[j] = '\0';
	return (s);
}

char **split(char *str, int c)
{
	char **split = malloc(sizeof(char *) * (count(str, c) + 1));
	int	i = 0;
	int j = 0;
	int start = 0;
	int end = 0;
	while (str[i])
	{
		start = i;
		while (str[i] && str[i] != c)
			i++;
		end = i;
		split[j++] = sub(str, start, end);
		while (str[i] && str[i] == c)
			i++;
	}
	split[j] = NULL;
	return (split);
}

void free_array(char **arr)
{
	int index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr[index]);
}

int main(int argc, char **argv)
{	
	char **output;

	atexit(leaks);
	if (argc != 2)
		return (0);
	output = split(argv[1], ' ');
	while (*output)
	{
		printf("%s\n", *output);
		output++;
	}
	free_array(output);

}
