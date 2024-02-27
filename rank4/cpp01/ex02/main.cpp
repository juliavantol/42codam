/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 13:27:51 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/27 14:51:44 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Memory address string: " << &string << std::endl;
	std::cout << "Memory address stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Value string: " << string << std::endl;
	std::cout << "Value stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value stringREF: " << stringREF << std::endl;

	return 0;

}
