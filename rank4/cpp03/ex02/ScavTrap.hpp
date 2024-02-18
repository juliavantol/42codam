/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 15:11:28 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/18 23:58:03 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

// public inheritance
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap & rhs);
		ScavTrap & operator=(ScavTrap const & rhs);
		~ScavTrap();

		void	guardGate(void);
		void	attack(const std::string & target);
};

#endif