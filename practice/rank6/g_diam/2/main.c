#include "g_diam.h"

// gcc -Wall -Wextra -Werror main.c utils.c -o run && ./run "2-3"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
}