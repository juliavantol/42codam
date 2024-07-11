/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 12:08:31 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/11 12:51:28 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Usage: ./convert [literal]" << RESET << std::endl;
		return 1;
	}
	std::string	input = std::string(argv[1]);
	ScalarConverter::convert(input);
	
}
