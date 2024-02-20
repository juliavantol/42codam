/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 12:52:25 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 13:03:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "[Brain] constructor has been called." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "[Brain] destructor has been called." << std::endl;
}

Brain::Brain(Brain const &rhs)
{
	*this = rhs;
	std::cout << "[Brain] copy constructor has been called." << std::endl;
}

Brain & Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	std::cout << "[Brain] copy assignment operator has been called." << std::endl;
	return *this;
}
