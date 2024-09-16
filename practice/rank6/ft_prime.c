#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	fprime(unsigned int nb)
{
	unsigned int	prime;

	if (nb == 1)
		printf("1");
	else
	{
		prime = 2;
		while (nb > 1)
		{
			if (nb % prime == 0)
			{
				printf("%d", prime);
				nb /= prime;
				if (nb > 1)
					printf("*");
				prime--;
			}
			prime++;
		}
	}
}

// gcc -Wall -Wextra -Werror ft_prime.c -o -run && ./run 225225 | cat -e
int		main(int ac, char **av)
{
	if (ac == 2 && *av[1])
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}