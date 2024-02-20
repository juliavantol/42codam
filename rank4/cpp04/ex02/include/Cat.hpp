/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 14:07:12 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 13:45:30 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
{
	private:
		Brain *_brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat &rhs);
		Cat & operator=(const Cat &rhs);
		void	makeSound(void) const;
};

#endif

