#include "g_diam.h"

t_node	*new_node(int n)
{
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->n = n;
	node->used = 0;
	node->next = NULL;
	return (node);
}

void	add_node(t_node **node_list, t_node *node)
{
	t_node *temp;

	if (!*node_list)
	{
		*node_list = node;
		return;
	}
	temp = *node_list;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	free_nodes(t_node **node_list)
{
	t_node *temp1;
	t_node *temp2;

	temp1 = *node_list;
	while (temp1)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	free(node_list);
}
