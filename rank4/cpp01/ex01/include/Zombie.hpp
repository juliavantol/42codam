/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 12:06:17 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/27 14:39:46 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	private:
		std::string _name;
		
	public:
		Zombie();
		~Zombie();
		void	announce(void) const;
		void	init(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
