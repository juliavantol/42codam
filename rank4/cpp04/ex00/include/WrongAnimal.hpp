/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 16:58:15 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/03/14 13:16:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &rhs);
		WrongAnimal & operator=(const WrongAnimal &rhs);
		virtual ~WrongAnimal();
	
		std::string		getType(void);
		void			makeSound(void) const;
};

#endif
