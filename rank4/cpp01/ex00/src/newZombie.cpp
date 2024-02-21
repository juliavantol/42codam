/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 12:06:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/21 16:59:30 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// creating a new Zombie object and returning a pointer to it
// Since the pointer is returned, the object needs to persist 
// beyond the scope of the function. Therefore, it's better to allocate this Zombie 
// object on the heap using new.
Zombie	*newZombie(std::string name)
{
	return new Zombie(name);
}
