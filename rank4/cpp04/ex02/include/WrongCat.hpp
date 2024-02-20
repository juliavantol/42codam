/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 17:28:16 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/19 17:28:19 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &rhs);
		WrongCat & operator=(const WrongCat &rhs);
		void	makeSound(void) const;
};

#endif

