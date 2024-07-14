/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 12:09:17 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/14 17:08:16 by Julia         ########   odam.nl         */
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
	else if (literal == "+inff" || literal == "-inff")
		return PSEUDO_FLOAT;
	else if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return PSEUDO_DOUBLE;
	return LITERAL_ERROR;
}

static int getInt(const std::string &literal)
{
	int	i;
	
	try
	{
		i = std::stoi(literal);
	}
	catch (const std::out_of_range &error)
	{
		if (literal[0] == '-')
			i = std::numeric_limits<int>::min();
		else
			i = std::numeric_limits<int>::max();
	}
	return i;
}

static void	printPseudoLiteral(const std::string &literal, int literalType)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literalType == PSEUDO_DOUBLE)
	{
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
	else if (literalType == PSEUDO_FLOAT)
	{
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	}
}

static void	printOutput(char c, int i, float f, double d, int literalType)
{	
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (f >= -FLT_MIN && f <= FLT_MAX)
	{
		if ((literalType == LITERAL_FLOAT || literalType == LITERAL_DOUBLE) && std::floor(f) != f)
			std::cout << "float: " << f << "f" << std::endl;
		else
			std::cout << "float: " << f << ".0f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
	if (d >= -DBL_MIN && d <= DBL_MAX)
	{
		if ((literalType == LITERAL_FLOAT || literalType == LITERAL_DOUBLE) && std::floor(d) != d)
			std::cout << "double: " << d << std::endl;
		else
			std::cout << "double: " << d << ".0" << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
}

void	ScalarConverter::convert(const std::string &literal)
{
	int		type = getType(literal);
	
	if (type == LITERAL_CHAR)
	{
		char c = literal[0];
		printOutput(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c), LITERAL_CHAR);
	}
	else if (type == LITERAL_INT)
	{
		int i = getInt(literal);
		printOutput(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i), LITERAL_INT);
	}
	else if (type == LITERAL_FLOAT)
	{
		float f = std::stof(literal);
		printOutput(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f), LITERAL_FLOAT);
	}
	else if (type == LITERAL_DOUBLE)
	{
		double d = std::stod(literal);
		printOutput(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d, LITERAL_DOUBLE);
	}
	else if (type == PSEUDO_DOUBLE || type == PSEUDO_FLOAT)
		printPseudoLiteral(literal, type);
	else
		std::cout << RED << "Invalid literal" << RESET << std::endl;
}
