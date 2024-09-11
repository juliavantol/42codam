#include "g_diam.h"

int		*parse_links(char *str, int *links)
{
	int	i = 0;
	int j = 0;
	int len = count_dashes(str);

	links = malloc(sizeof(int) * (len * 2 + 1));
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

t_node	**parse_nodes(t_node **nodelist, int *links)
{
	t_node	*temp;
	int		i = 0;

	nodelist = malloc(sizeof(t_node *));
	*nodelist = NULL;
	while (links[i] != -1)
	{
		if (is_new(nodelist, links[i]) == 1)
		{
			temp = new_node(links[i]);
			add_node(nodelist, temp);
		}
		i++;
	}
	return (nodelist);
}
