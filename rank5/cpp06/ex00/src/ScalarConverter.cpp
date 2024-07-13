/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 12:09:17 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/13 18:28:28 by Julia         ########   odam.nl         */
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
	else if (literal == "nan" || literal == "+inf" || literal == "+inff" || "-inf" || literal == "-inff")
		return LITERAL_PSEUDO;
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

static void	printPseudoLiteral(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (literal == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan"<< std::endl;
	}
}

static void	printOutput(char c, int i, float f, double d, int literalType)
{
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (literalType == LITERAL_FLOAT || literalType == LITERAL_DOUBLE)
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &literal)
{
	int		type = getType(literal);
	int		i;
	char	c;
	float	f;
	double	d;

	switch (type)
	{
		case LITERAL_CHAR:
			c = literal[0];
			printOutput(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c), LITERAL_CHAR);
			break;
		case LITERAL_INT:
			i = getInt(literal);
			printOutput(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i), LITERAL_INT);
			break;
		case LITERAL_FLOAT:
			f = std::stof(literal);
			printOutput(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f), LITERAL_FLOAT);
			break;
		case LITERAL_DOUBLE:
			d = std::stod(literal);
			printOutput(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d, LITERAL_DOUBLE);
			break;
		case LITERAL_PSEUDO:
			printPseudoLiteral(literal);
			break;
		default:
			std::cout << RED << "Unrecognised literal" << RESET << std::endl;
	}
}
