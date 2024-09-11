#include "g_diam.h"

int		is_link(int *links, int n1, int n2)
{
	int	i = 0;

	while (links[i])
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

int		find_max(t_node **node_list, int *links, int n, int old_max)
{
	t_node *temp = *node_list;
	int new_max;
	int max = old_max;

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

int		g_diam(t_node **node_list, int *links)
{
	t_node *temp = *node_list;
	int new_max = 0;
	int max = 1;

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
	int		output = 0;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	links = parse_links(argv[1], links);
	node_list = parse_nodes(node_list, links);
	output = g_diam(node_list, links);
	put_num(output);
	write(1, "\n", 1);
}