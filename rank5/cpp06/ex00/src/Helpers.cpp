/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Helpers.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/13 17:59:24 by Julia         #+#    #+#                 */
/*   Updated: 2024/07/13 18:02:19 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Helpers.hpp"

bool isChar(const std::string &literal)
{
	if (literal.length() != 1)
		return false;
	if (isprint(literal[0]))
		return true;
	return false;
}

bool isInt(const std::string &literal)
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

bool isFloat(const std::string &literal)
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

bool isDouble(const std::string &literal)
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
