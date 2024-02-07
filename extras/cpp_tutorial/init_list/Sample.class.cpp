/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sample.class.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:11:32 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/07 16:22:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3)
{
	std::cout << "Constructor called" << std::endl;
	
	std::cout << "this->a1 = " << this->a1 << std::endl;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	std::cout << "this->a3 = " << this->a3 << std::endl;
}

Sample::~Sample(void)
{
	std::cout << "Deconstructor called" << std::endl;
}
