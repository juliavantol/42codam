/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 12:09:17 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/12 18:51:52 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

static void	convertChar(const std::string &literal)
{
	char	c = literal[0];
	
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void	convertInt(const std::string &literal)
{
	try
	{
		int	i = std::stoi(literal);
		
		std::cout << "char: " << static_cast<char>(i) << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	}
	catch(std::exception &err)
	{
		std::cerr << RED << "Conversion failed" << RESET << std::endl;
	}
}

static void	convertFloat(const std::string &literal)
{
	try
	{
		float	f = std::stof(literal);

		std::cout << "char: " << static_cast<char>(f) << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	catch(std::exception &err)
	{
		std::cerr << RED << "Conversion failed" << RESET << std::endl;
	}
}

static void	convertDouble(const std::string &literal)
{
	try
	{
		double	d = std::stod(literal);

		std::cout << "char: " << static_cast<char>(d) << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	catch(std::exception &err)
	{
		std::cerr << RED << "Conversion failed" << RESET << std::endl;
	}
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

	switch (type)
	{
		case LITERAL_CHAR:
			convertChar(literal);
			break;
		case LITERAL_INT:
			convertInt(literal);
			break;
		case LITERAL_FLOAT:
			convertFloat(literal);
			break;
		case LITERAL_DOUBLE:
			convertDouble(literal);
			break;
		default:
			std::cout << "Error" << std::endl;
	}
}
