/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 12:09:17 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/12 01:00:33 by Julia         ########   odam.nl         */
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

static bool isChar(const std::string &literal)
{
	if (literal.length() != 1)
		return false;
	if (isprint(literal[0]))
		return true;
	return false;
}

static bool isFloat(const std::string &literal)
{
	int i = 0, j = 0, x = 0;
	int len = literal.length();
	int	decimalIndex = literal.find(".");

	if (decimalIndex == -1 || literal[len - 1] != 'f' || !isdigit(literal[decimalIndex + 1]))
		return false;
	if (literal[0] == '-')
		i++;
	for (j = i; j < decimalIndex; j++)
	{
		if (isdigit(literal[j]) == false)
			return false;
	}
	for (x = decimalIndex + 1; x < len - 1; x++)
	{
		if (isdigit(literal[x]) == false)
			return false;
	}
	return true;
}

static bool isDouble(const std::string &literal)
{
	int i = 0, j = 0, x = 0;
	int len = literal.length();
	int	decimalIndex = literal.find(".");

	if (decimalIndex == -1 || !isdigit(literal[decimalIndex + 1]))
		return false;
	if (literal[0] == '-')
		i++;
	for (j = i; j < decimalIndex; j++)
	{
		if (isdigit(literal[j]) == false)
			return false;
	}
	for (x = decimalIndex + 1; x < len; x++)
	{
		if (isdigit(literal[x]) == false)
			return false;
	}
	return true;
}

static int getType(const std::string &literal)
{
	if (isInt(literal))
		return LITERAL_INT;
	else if (isChar(literal))
		return LITERAL_CHAR;
	else if (isFloat(literal))
		return LITERAL_FLOAT;
	else if (isDouble(literal))
		return LITERAL_DOUBLE;
	return LITERAL_ERROR;
}

void	ScalarConverter::convert(const std::string &literal)
{
	int	type = getType(literal);
	
	std::cout << literal << std::endl;
	switch (type)
	{
		case LITERAL_CHAR:
			std::cout << "Type: char" << std::endl;
			break;
		case LITERAL_INT:
			std::cout << "Type: int" << std::endl;
			break;
		case LITERAL_FLOAT:
			std::cout << "Type: float" << std::endl;
			break;
		case LITERAL_DOUBLE:
			std::cout << "Type: double" << std::endl;
			break;
		default:
			std::cout << "Error" << std::endl;
	}
}
