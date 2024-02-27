/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 12:03:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/27 14:47:10 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	int		N = 5;
	Zombie	*horde = zombieHorde(N, "Zombie");
	std::cout << std::endl;
	
	if (horde)
	{
		for (int i = 0; i < N; i++)
			horde[i].announce();

		std::cout << std::endl;
		delete [] horde;
	}
	return 0;
}
