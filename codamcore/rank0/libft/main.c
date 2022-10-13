/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:55:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/13 19:02:07 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	source[] = "GeeksForGeeks";
    char* target = strdup(source);
 
    printf("%s\n", target);

	return (0);
}
