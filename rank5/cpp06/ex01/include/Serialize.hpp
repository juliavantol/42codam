/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialize.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/14 17:11:04 by Julia         #+#    #+#                 */
/*   Updated: 2024/07/14 19:46:38 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include "Data.hpp"

# define GREEN	"\033[32m"
# define BOLD	"\033[1m"
# define RESET	"\033[0m"
# define RED	"\033[31m"

class Serialize
{
	private:
		Serialize();
	
	public:
		~Serialize();
		Serialize(const Serialize &other);
		Serialize &operator=(const Serialize &other);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif