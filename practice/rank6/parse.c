#include "g_diam.h"

int	count_dash(char *str)
{
	int i = 0;
	int n = 0;

	while (str[i])
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	return (n);
}

int ft_atoi(char *str)
{
	int i = 0;
	int n = 0;
	int power = 1;

	while(str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	while (i >= 0)
	{
		n += (str[i] - '0') * power; 
		power *= 10;
		i--;
	}
	return n;
}

int ft_skip(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (-1);
}

int		*parse_links(char *str, int *links)
{
	int i = 0;
	int j = 0;
	int	n = count_dash(str);

	links = malloc(sizeof(int) * (n * 2 + 1));
	if (!links)
		return (NULL);
	
	while (i != -1)
	{
		links[j] = ft_atoi(&str[i]);
		i = ft_skip(str, i, '-');
		j++;
		links[j] = ft_atoi(&str[i]);
		i = ft_skip(str, i, ' ');
		j++;
	}
	links[j] = -1;
	return (links);
}

int	is_new(t_node **node_list, int n)
{
	t_node *temp = *node_list;

	while (temp)
	{
		if (temp->n == n)
			return 0;
		temp = temp->next;
	}
	return 1;
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
				return (NULL);
			}
			add_node(node_list, node);
		}
		i++;
	}
	return (node_list);
}
