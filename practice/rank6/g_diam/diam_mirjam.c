# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				n;
	int				used;
	struct s_node	*next;
}	t_node;

t_node	*nodenew(int n);
void	nodeadd(t_node **nodelist, t_node *node);
void	nodefree(t_node **nodelist);

int		ft_count_dash(char *str);
int		ft_skip(char *str, int i, char c);
int		ft_atoi(char *str);
void	ft_putnbr(int n);

int		*parse_links(char *str, int *links);
t_node	**parse_nodes(int *links, t_node **nodelist);
int		is_new_number(t_node **nodelist, int n);

int		is_link(int *links, int n1, int n2);
int		find_max(t_node **nodelist, int *links, int n, int oldmax);
int		g_diam(t_node **nodelist, int *links);

t_node	*nodenew(int n)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->n = n;
	node->used = 0;
	node->next = NULL;
	return (node);
}

void	nodeadd(t_node **nodelist, t_node *node)
{
	t_node	*tmp;

	if (!*nodelist)
	{
		*nodelist = node;
		return;
	}
	tmp = *nodelist;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	nodefree(t_node **nodelist)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = *nodelist;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	free(nodelist);
}

int	*parse_links(char *str, int *links)
{
	int		n;
	int		i;
	int		j;

	n = ft_count_dash(str);
	links = malloc(sizeof(int) * (n * 2 + 1));
	if (!links)
		return (NULL);
	i = 0;
	j = 0;
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

t_node	**parse_nodes(int *links, t_node **nodelist)
{
	t_node	*node;
	int		i;

	nodelist = malloc(sizeof(t_node *));
	if (!nodelist)
		return (NULL);
	*nodelist = NULL;
	i = 0;
	while (links[i] != -1)
	{
		if (is_new_number(nodelist, links[i]) == 1)
		{
			node = nodenew(links[i]);
			if (!node)
			{
				nodefree(nodelist);
				return (NULL);
			}
			nodeadd(nodelist, node);
		}
		i++;
	}
	return (nodelist);
}

int	is_new_number(t_node **nodelist, int n)
{
	t_node	*tmp;

	tmp = *nodelist;
	while (tmp)
	{
		if (tmp->n == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_count_dash(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	return (n);
}

int	ft_skip(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	pow;
	int	n;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	pow = 1;
	n = 0;
	while (i >= 0)
	{
		n += (str[i] - '0') * pow;
		pow *= 10;
		i--;
	}
	return (n);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

int	is_link(int *links, int n1, int n2)
{
	int	i;

	i = 0;
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

int	find_max(t_node **nodelist, int *links, int n, int oldmax)
{
	t_node	*tmp;
	int		max;
	int		newmax;

	max = oldmax;
	tmp = *nodelist;
	while (tmp)
	{
		if (tmp->used == 0 && is_link(links, n, tmp->n) == 1)
		{
			tmp->used = 1;
			newmax = find_max(nodelist, links, tmp->n, oldmax + 1);
			tmp->used = 0;
			if (newmax > max)
				max = newmax;
		}
		tmp = tmp->next;
	}
	return (max);
}

int	g_diam(t_node **nodelist, int *links)
{
	t_node	*tmp;
	int		max;
	int		newmax;

	max = 1;
	tmp = *nodelist;
	while (tmp)
	{
		tmp->used = 1;
		newmax = find_max(nodelist, links, tmp->n, 1);
		tmp->used = 0;
		if (newmax > max)
			max = newmax;
		tmp = tmp->next;
	}
	return (max);
}

int	main(int argc, char **argv)
{
	t_node	**nodelist;
	int		*links;
	int		max;

	if (argc == 2)
	{
		links = NULL;
		links = parse_links(argv[1], links);
		if (!links)
			return (1);
		nodelist = NULL;
		nodelist = parse_nodes(links, nodelist);
		if (!nodelist)
		{
			free(links);
			return (1);
		}
		max = g_diam(nodelist, links);
		free(links);
		nodefree(nodelist);
		ft_putnbr(max);
	}
	write(1, "\n", 1);
	return (0);
}
