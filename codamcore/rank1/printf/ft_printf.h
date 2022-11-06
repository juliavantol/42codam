/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 11:04:47 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/06 20:56:53 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char	*c, ...);
int		ft_putstr(char *s, int fd);
int		new_itoa(int n);
void	to_hex(unsigned int num, int count);
int		test(unsigned int n);
int		count_hex(unsigned int n);

#endif
