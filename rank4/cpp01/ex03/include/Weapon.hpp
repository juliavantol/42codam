/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 13:42:31 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/13 14:29:30 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class	Weapon
{
	private:
		std::string _type;
	
	public:
		Weapon(std::string type);
		Weapon();
		~Weapon();
		const 		std::string	&getType(void) const;
		void		setType(std::string type);
};

#endif