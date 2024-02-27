/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 13:26:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/27 14:47:56 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombieHorde = nullptr;
	if (N < 0)
		return NULL;
	
	try {
		zombieHorde = new Zombie[N];
	}
	catch (const std::bad_alloc) {
		std::cerr << "Allocation error" << std::endl;
		return zombieHorde;
	}
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
		zombieHorde[i].init(name);

	return zombieHorde;
}
