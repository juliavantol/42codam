/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 11:18:23 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/19 00:24:25 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "includes/libft/libft.h"
# include "includes/printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

char	*find_path(char **envp);
int	loop_paths(char **paths, char *command);
int	loop_paths2(char *paths, char *command);

#endif