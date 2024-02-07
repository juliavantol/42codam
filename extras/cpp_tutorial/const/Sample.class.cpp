/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sample.class.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:11:32 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/07 16:58:55 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(float const f) : pi(f), qd(42)
{
	std::cout << "Constructor called" << std::endl;
}

Sample::~Sample(void)
{
	std::cout << "Deconstructor called" << std::endl;
}

// const tells the compiler that this member function
// won't alter the current instance;
void	Sample::bar(void) const
{
	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->qd << std::endl;

	// the following wont work cause its defined as a const
	// this->qd = 0;
}

// if you write a member function that doesnt alter the instance
// always declare const