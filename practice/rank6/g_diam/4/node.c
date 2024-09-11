#include "g_diam.h"

void	add_node(t_node **nodelist, t_node *node)
{
	t_node	*temp = *nodelist;

	if (!*nodelist)
	{
		*nodelist = node;
		return;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

t_node	*new_node(int n)
{
	t_node *node = malloc(sizeof(t_node));

	node->n = n;
	node->used = 0;
	node->next = NULL;
	return (node);
}

void	free_nodes(t_node **node_list)
{
	t_node	*temp1 = *node_list;
	t_node	*temp2;

	while (temp1)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	free(node_list);
}
