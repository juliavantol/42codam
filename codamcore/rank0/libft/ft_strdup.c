/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 14:04:33 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/15 13:03:41 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(const char *s)
{
	const char	*new;
	char		*l;
	int			index;

	index = 0;
	new = s;
	l = "a";
	while (new[index] != '\0')
		index++;
	return (l);
}
