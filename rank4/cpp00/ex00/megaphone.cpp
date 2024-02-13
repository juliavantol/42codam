/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 17:50:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/02 13:42:39 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < argc; i++)
		{
			for (size_t	j = 0; j < strlen(argv[i]); j++)
				std::cout << (char)toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}
