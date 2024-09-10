#ifndef G_DIAM_H
#define G_DIAM_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				n;
	int 			used;
	struct s_node	*next;
}	t_node;


#endif

void	put_num(int n);
int		ft_atoi(char *str);
int		ft_skip(char *str, int i, char c);
int		count_dashes(char *str);