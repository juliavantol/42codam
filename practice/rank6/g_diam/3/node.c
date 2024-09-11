#include "g_diam.h"

void	add_node(t_node **node_list, t_node *node)
{
	if (*node_list == NULL)
	{
		*node_list = node;
		return;
	}
	t_node	*temp = *node_list;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
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

t_node	*new_node(int n)
{
	t_node	*node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->n = n;
	node->used = 0;
	node->next = NULL;
	return (node);
}
