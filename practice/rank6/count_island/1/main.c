#include "island.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	printf("%s\n", argv[1]);
}

// gcc -Wall -Wextra -Werror main.c utils.c -o run && ./run