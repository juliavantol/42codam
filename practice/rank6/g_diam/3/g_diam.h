#ifndef G_DIAM_H
#define G_DIAM_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				n;
	int				used;
	struct s_node	*next;
} t_node;

// 4 utils
int		ft_atoi(char *str);
int		ft_skip(char *str, int i, char c);
int		count_dashes(char *str);
void	put_num(int i);

int		is_new(t_node **node_list, int n);
int		*parse_links(char *str, int *links);
t_node	**parse_nodes(t_node **node_list, int *links);

// nodes
void	add_node(t_node **node_list, t_node *node);
void	free_nodes(t_node **node_list);
t_node	*new_node(int n);

#endif
