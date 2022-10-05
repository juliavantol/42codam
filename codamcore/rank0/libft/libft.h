/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 14:31:55 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/05 14:39:45 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOO_DOT_H
#define FOO_DOT_H

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int ft_isalnum(int c);
int	ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *s);
int	ft_toupper(int c);
int	ft_tolower(int c);
void	*memset(void *s, int c, size_t n);

#endif /* FOO_DOT_H */