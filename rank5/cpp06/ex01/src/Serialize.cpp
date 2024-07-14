/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialize.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/14 17:26:47 by Julia         #+#    #+#                 */
/*   Updated: 2024/07/14 22:40:10 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize(void) {};

Serialize::~Serialize(void) {};

Serialize::Serialize(const Serialize &other)
{
	(void)other;
}

Serialize & Serialize::operator=(const Serialize &other)
{
	(void) other;
	return *this;
}

uintptr_t Serialize::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}