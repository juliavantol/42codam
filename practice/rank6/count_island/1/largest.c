#include "island.h"

int		find_size(char *str, int i, int len)
{
	int size = 1;
	int j = i - len;

	str[i] = 'Y';
	if (j >= 0 && str[j] == 'X')
		size += find_size(str, j, len);
	j = i - 1;
	if (j >= 0 && str[j] == 'X')
		size += find_size(str, j, len);
	j = i + 1;
	if (j < ft_strlen(str) && str[j] == 'X')
		size += find_size(str, j, len);
	j = i + len;
	if (j < ft_strlen(str) && str[j] == 'X')
		size += find_size(str, j, len);
	return (size);
}

void	largest_island(char *str)
{
	int maxsize = 0;
	int size;
	int len = find_nl(str) + 1;
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
		{
			size = find_size(str, i , len);
			if (size > maxsize)
				maxsize = size;
		}
		i++;
	}
	printf("%d\n", maxsize);
}