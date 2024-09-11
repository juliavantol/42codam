#ifndef ISLAND_H
#define ISLAND_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// utils


int		ft_strlen(char *str);
int		find_nl(char *str);
void	ft_bzero(char *str, int len);
char	*ft_calloc(int len);
char	*ft_strjoin(char *s1, char *str2);

void	island(char *str);
void	largest_island(char *str);
void	count_island(char *str);

#endif