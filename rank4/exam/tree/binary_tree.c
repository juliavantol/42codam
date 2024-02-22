#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

// Function to create a new node
t_node *newNode(int data)
{
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
    node->value = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int	tree_height(t_node *root)
{
	int	left_height;
	int	right_height;

	if (root == NULL)
		return (0);
	left_height = tree_height(root->left);
	right_height = tree_height(root->right);
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

int	count_nodes(t_node *root)
{
	if (root == NULL)
		return (0);
	return (count_nodes(root->left) + count_nodes(root->right) + 1);
}

int main(void)
{
	t_node *root = NULL;

	root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->left = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

	printf("height: %d\n", tree_height(root));
	printf("total nodes: %d\n", count_nodes(root));
}
