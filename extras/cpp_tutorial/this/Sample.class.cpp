/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sample.class.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:11:32 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/07 15:55:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	
	this->foo = 10;
	std::cout << "this->foo: " << this->foo << std::endl;
	this->mem();
}

Sample::~Sample(void)
{
	std::cout << "Deconstructor called" << std::endl;
}

void	Sample::mem(void)
{
	std::cout << "Member function was called" << std::endl;
}