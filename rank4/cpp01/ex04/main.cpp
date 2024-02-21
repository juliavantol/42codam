/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 01:31:21 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/21 17:33:03 by juvan-to      ########   odam.nl         */
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

void	read_input(std::ifstream &input, std::ofstream &output, std::string s1, std::string s2)
{
	std::string		line;

	while (getline(input, line))
	{
		output << replace_string(s1, s2, line);
		if (s1.compare("\\n") != 0)
			output << std::endl;
	}
	input.close();
	output.close();
}

int main(int argc, char **argv)
{
	std::ofstream	output;
	std::ifstream	input;

	if (argc != 4)
	{
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	input.open(argv[1]);
	if (!input.is_open())
	{
		std::cout << "Unable to open input file" << std::endl;
		return 0;
	}
	std::string filename = std::string(argv[1]) + ".replace";
	output.open(filename.c_str());
	if (!output.is_open())
	{
		std::cout << "Unable to open output file" << std::endl;
		input.close();
		return 0;
	}
	read_input(input, output, argv[2], argv[3]);
	return 0;
}
