/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/10 16:20:22 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/10 16:24:44 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern & Intern::operator=(const Intern &other)
{
	(void) other;
	return *this;
}