#include "g_diam.h"

int	*parse_links(char *str, int *links)
{
	int i = 0;
	int	j = 0;
	int count = count_dashes(str);

	links = malloc(sizeof(int) * (count * 2 + 1));
	if (!links)
		return (NULL);
	while (i != -1)
	{
		links[j++] = ft_atoi(&str[i]);
		i = ft_skip(str, i, '-');
		links[j++] = ft_atoi(&str[i]);
		i = ft_skip(str, i, ' ');
	}
	links[j] = -1;
	return (links);
}

int		is_new(t_node **node_list, int n)
{
	t_node	*temp = *node_list;

	while (temp)
	{
		if (temp->n == n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_node	**parse_nodes(t_node **node_list, int *links)
{
	t_node	*node;
	int		i = 0;

	node_list = malloc(sizeof(t_node *));
	if (!node_list)
		return (NULL);
	*node_list = NULL;
	while (links[i] != -1)
	{
		if (is_new(node_list, links[i]) == 1)
		{
			node = new_node(links[i]);
			if (!node)
			{
				free_nodes(node_list);
				return(NULL);
			}
			add_node(node_list, node);
		}
		i++;
	}
	return (node_list);
}
