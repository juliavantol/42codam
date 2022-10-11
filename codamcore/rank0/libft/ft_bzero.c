/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 17:02:18 by Julia         #+#    #+#                 */
/*   Updated: 2022/10/11 17:09:51 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void    ft_bzero(void *s, size_t n)
{
    unsigned char   *p;
    size_t  index;

    p = s;
    index = 0;
    while (index < n)
    {
        p[index] = '\0';
        index++;
    }
}