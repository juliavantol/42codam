/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 12:06:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/26 14:39:58 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates a Zombie instance on the heap and returns a pointer to it
Zombie	*newZombie(std::string name)
{
	Zombie	*new_zombie = nullptr;

	try {
		new_zombie = new Zombie(name);
	}
	catch (const std::bad_alloc) {
		std::cerr << "Allocation error" << std::endl;
	}
	return new_zombie;
}
