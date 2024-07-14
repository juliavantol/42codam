/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 12:08:31 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/14 17:29:21 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Usage: ./convert [literal]" << RESET << std::endl;
		return 1;
	}
	std::string	input = std::string(argv[1]);
	try
	{
		// ScalarConverter::convert(input);
	}
	catch (std::exception &error)
	{
		std::cout << RED << "Conversion error" << RESET << std::endl;
	}
}
