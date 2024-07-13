/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 12:09:17 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/13 17:15:11 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// 2147483647

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void) other;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &other)
{
	(void) other;
	return *this;
}

static bool isChar(const std::string &literal)
{
	if (literal.length() != 1)
		return false;
	if (isprint(literal[0]))
		return true;
	return false;
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
	if (isdigit(literal[i]) == false && literal[i] != '\0')
		return false;
	return true;
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

static void	printOutput(char c, int i, float f, double d)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
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
	int		type = getType(literal);
	char	c;
	int 	i;
	float	f;
	double	d;

	switch (type)
	{
		case LITERAL_CHAR:
			c = literal[0];
			printOutput(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
			break;
		case LITERAL_INT:
			i = std::stoi(literal);
			printOutput(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
			break;
		case LITERAL_FLOAT:
			f = std::stof(literal);
			printOutput(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
			break;
		case LITERAL_DOUBLE:
			d = std::stod(literal);
			printOutput(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
			break;
		default:
			std::cout << "Error" << std::endl;
	}
}
