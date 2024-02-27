/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/26 00:05:32 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/27 22:43:11 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Sed.hpp"

int main(int argc, char **argv)
{
	Sed				sed;
	
	if (argc != 4 || std::string(argv[1]).empty() || std::string(argv[2]).empty())
	{
		std::cout << "Invalid input" << std::endl;
		return 1;
	}
	sed.parseInput(argv[1], argv[2], argv[3]);
	if (sed.getErrorStatus() == true)
		return 1;
	sed.replaceString(sed.getStr1(), sed.getStr2(), sed.getWholeFile());
	sed.writeOutput(std::string(argv[1]) + ".replace");	
	return 0;
}
