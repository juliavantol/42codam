#include "g_diam.h"

// gcc -Wall -Wextra -Werror main.c utils.c parse.c node.c -o run && ./run "17-5 5-8 8-2 2-8 2-8 17-21 21-2 5-2 2-6 6-14 6-12 12-19 19-14 14-42" | cat -e

int is_link(int *links, int n1, int n2)
{
	int i = 0;

	while (links[i] != -1)
	{
		if (links[i] == n1 || links[i] == n2)
		{
			if (links[i + 1] == n1 || links[i + 1] == n2)
				return (1);
		}
		i++;
	}
	return (0);
}

int	find_max(t_node **node_list, int *links, int n, int old_max)
{
	t_node *temp = *node_list;
	int max = old_max;
	int new_max;

	while (temp)
	{
		if (temp->used == 0 && is_link(links, temp->n, n) == 1)
		{
			temp->used = 1;
			new_max = find_max(node_list, links, temp->n, old_max + 1);
			temp->used = 0;
			if (new_max > max)
				max = new_max;
		}
		temp = temp->next; 
	}
	return (max);
}

int	g_diam(t_node **node_list, int *links)
{
	t_node *temp = *node_list;
	int max = 1;
	int new_max;

	while (temp)
	{
		temp->used = 1;
		new_max = find_max(node_list, links, temp->n, 1);
		temp->used = 0;
		if (new_max > max)
			max = new_max;
		temp = temp->next; 
	}
	return (max);
}

int main(int argc, char **argv)
{
	int		*links = NULL;
	t_node	**node_list = NULL;
	int		output;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}

	links = parse_links(argv[1], links);
	if (!links)
		return (-1);
	node_list = parse_nodes(node_list, links);
	if (!node_list)
	{
		free(links);
		return (-1);
	}
	output = g_diam(node_list, links);
	put_num(output);
	write(1, "\n", 1);
	free_nodes(node_list);
	free(links);
	return (0);
}