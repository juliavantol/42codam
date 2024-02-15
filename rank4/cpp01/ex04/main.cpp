/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 01:31:21 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/15 02:40:05 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	replace_string(std::string s1, std::string s2, std::string line)
{
	std::string		output = line;
	size_t			found = line.find(s1);

	if (s1.empty())
		return output;
	while (found != std::string::npos)
	{
		output.erase(found, s1.length());
		if (s2.compare("\\n") == 0)
			output.insert(found, "\n");
		else
			output.insert(found, s2);
		found = output.find(s1, found + s1.length());
	}
	return output;
}

int main(int argc, char **argv)
{
	std::ofstream	output;
	std::ifstream	input;
	std::string		line;

	if (argc != 4)
	{
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	input.open(argv[1]);
	output.open("output.txt");
	if (input.is_open() && output.is_open())
	{
		while (getline(input, line))
		{
			output << replace_string(argv[2], argv[3], line);
			if (std::string(argv[2]).compare("\\n") != 0)
				output << std::endl;
		}
		input.close();
		output.close();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
		return 0;
	}
	return 0;
}
