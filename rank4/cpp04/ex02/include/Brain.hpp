/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 12:54:01 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 13:08:17 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &rhs);
		Brain & operator=(const Brain &rhs);
		~Brain();
};

#endif
