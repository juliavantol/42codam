/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/26 00:05:32 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/27 13:39:10 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Sed.hpp"

int main(int argc, char **argv)
{
	Sed				sed;
	
	if (argc != 4)
	{
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	sed.readFile(argv[1]);
	if (sed.getErrorStatus() == true)
		return 1;
	sed.replaceString(argv[2], argv[3], sed.wholeFile);
	sed.writeOutput(std::string(argv[1]) + ".replace");	
	return 0;
}
