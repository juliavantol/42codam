/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 01:31:21 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/14 16:04:08 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	replace_string(int len, std::string s1, std::string s2, std::string line)
{
	std::string		output;
	std::string		temp;
	size_t			found;

	output = line;
	if (s1.empty() || s2.empty())
		return output;
	found = line.find(s1);
	while (found != std::string::npos)
	{
		temp = line.substr(found + len, std::string::npos);
		output.erase(found, std::string::npos);
		output.append(s2);
		output.append(temp);
		found = line.find(s1, found + len);
	}
	return output;
}

int main(int argc, char **argv)
{
	std::ofstream	output;
	std::ifstream	input;
	std::string		line;
	char			*filename = argv[1];

	if (argc != 4)
	{
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	int len = std::string(argv[2]).length();
	input.open(filename);
	output.open("output.txt");
	if (input.is_open() && output.is_open())
	{
		while (getline(input, line))
			output << replace_string(len, argv[2], argv[3], line) << std::endl;
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
