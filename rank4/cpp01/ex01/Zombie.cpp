/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 12:07:03 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/13 13:24:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A zombie has been constructed." << std::endl;
	return;
}
Zombie::~Zombie(void)
{
	std::cout << this->_name << " has died." << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::init(std::string name)
{
	this->_name = name;
}

Zombie	*zombieHorde(int N, std::string name)
{
	if (N < 0)
		return NULL;
	
	Zombie	*zombieHorde = new Zombie[N];
	if (!zombieHorde)
		return NULL;
	
	for (int i = 0; i < N; i++)
		zombieHorde[i].init(name);

	return zombieHorde;
}