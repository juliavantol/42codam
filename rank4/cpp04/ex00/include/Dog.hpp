/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 14:04:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/19 14:23:52 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &rhs);
		Dog & operator=(const Dog &rhs);
};

#endif

