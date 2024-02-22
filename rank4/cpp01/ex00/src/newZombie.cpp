/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 12:06:43 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/21 17:43:49 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates a Zombie instance on the heap and returns a pointer to it
Zombie	*newZombie(std::string name)
{
	return new Zombie(name);
}
