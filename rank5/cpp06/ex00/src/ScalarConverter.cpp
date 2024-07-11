/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 12:09:17 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/11 13:55:29 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	
}

ScalarConverter::~ScalarConverter(void)
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void) other;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &other)
{
	(void) other;
	return *this;
}

static bool isInt(const std::string &literal)
{
	int	i = 0;
	
	if (literal[0] == '-')
		i++;
	while (literal[i])
	{
		if (isdigit(literal[i]) == false)
			return false;
		i++;
	}
	return true;
}

static int getType(const std::string &literal)
{
	if (isInt(literal))
		return LITERAL_INT;
	return LITERAL_ERROR;
}

void	ScalarConverter::convert(const std::string &literal)
{
	std::cout << literal << std::endl;
	std::cout << getType(literal) << std::endl;
}
