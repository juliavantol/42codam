/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 13:12:10 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 13:57:47 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class	AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		AAnimal(const AAnimal &rhs);
		AAnimal & operator=(const AAnimal &rhs);
		virtual ~AAnimal();
	
		std::string		getType(void);
		virtual void	makeSound(void) const = 0;
		
};

#endif