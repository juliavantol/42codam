/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 13:12:10 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/19 14:16:10 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		~Animal();
		Animal(const Animal &rhs);
		Animal & operator=(const Animal &rhs);
		std::string	getType(void);
		
};

#endif