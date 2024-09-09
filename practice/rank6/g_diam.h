#ifndef G_DIAM_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
	int				n;
	int				used;
	struct s_node	*next;
}	t_node;

t_node	*new_node(int n);
void	add_node(t_node **node_list, t_node *node);
void	free_nodes(t_node **node_list);

int		*parse_links(char *str, int *links);

t_node	**parse_nodes(t_node **node_list, int *links);

#endif