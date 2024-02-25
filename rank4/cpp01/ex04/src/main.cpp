/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/26 00:05:32 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/26 00:43:14 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Sed.hpp"

int main(int argc, char **argv)
{
	Sed				sed;
	std::ifstream	input;
	std::string		whole_file = "";
	std::string		output = "";
	
	if (argc != 4)
	{
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	whole_file = sed.readFile(argv[1]);
	if (sed.getErrorStatus() == true)
		return 1;
	output = sed.replaceString(whole_file, argv[2], argv[3]);
	sed.writeOutput(std::string(argv[1]) + ".replace", output);	
	return 0;
}
