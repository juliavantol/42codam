/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 12:06:51 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/21 17:43:00 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates a Zombie instance on the stack
void randomChump(std::string name)
{
	Zombie	randomChump = Zombie(name);

	randomChump.announce();
}
