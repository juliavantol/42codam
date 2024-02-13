/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 13:26:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/13 13:26:35 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N < 0)
		return NULL;
	
	Zombie	*zombieHorde = new Zombie[N];
	if (!zombieHorde)
		return NULL;
	
	for (int i = 0; i < N; i++)
		zombieHorde[i].init(name);

	return zombieHorde;
}
