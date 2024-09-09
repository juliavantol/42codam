#include "g_diam.h"

void	ft_putnum(int n)
{
	char c;

	if (n > 9)
	{
		ft_putnum(n / 10);
		ft_putnum(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

int	is_link(int *links, int n1, int n2)
{
	int i = 0;

	while (links[i] != -1)
	{
		if (n1 == links[i] || n2 == links[i])
		{
			if (n1 == links[i + 1] || n2 == links[i + 1])
				return (1);
		}
		i += 2;
	}
	return (0);
}

int	find_max(t_node **node_list, int *links, int n, int old_max)
{
	t_node	*temp = *node_list;
	int		max = old_max;
	int		new_max;

	while (temp)
	{
		if (temp->used == 0 && is_link(links, n, temp->n) == 1)
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
	t_node	*temp = *node_list;
	int		max = 1;
	int		new_max;

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
	t_node	**node_list = NULL;
	int		*links = NULL;
	int		max;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	links = parse_links(argv[1], links);
	if (!links)
		return 1;
	node_list = parse_nodes(node_list, links);
	if (!node_list)
	{
		free(links);
		return 1;
	}
	max = g_diam(node_list, links);
	free(links);
	free_nodes(node_list);
	ft_putnum(max);
	write(1, "\n", 1);
}