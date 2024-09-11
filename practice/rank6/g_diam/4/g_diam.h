#ifndef G_DIAM_H
#define G_DIAM_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int				used;
	int				n;
	struct s_node	*next;
} t_node;

// utils
int		ft_atoi(char *str);
int 	count_dashes(char *str);
int		ft_skip(char *str, int i, char c);
void	put_num(int num);
int		is_new(t_node **node_list, int n);

int		*parse_links(char *str, int *links);
t_node	**parse_nodes(t_node **nodelist, int *links);

int		g_diam(t_node **node_list, int *links);
int		find_max(t_node **node_list, int *links, int n, int old_max);
int		is_link(int *links, int n1, int n2);

void	add_node(t_node **nodelist, t_node *node);
t_node	*new_node(int n);
void	free_nodes(t_node **node_list);

#endif