/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sed.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/25 23:55:26 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/26 00:44:46 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <fstream>
#include <iostream>

Sed::Sed(void)
{
	this->errorOccured = false;
}

std::string	Sed::replaceString(std::string str, std::string s1, std::string s2)
{
	std::string		output = str;
	size_t			found = str.find(s1);

	if (s1.empty())
		return output;
	while (found != std::string::npos)
	{
		output.erase(found, s1.length());
		output.insert(found, s2);
		found = output.find(s1, found + s2.length());
	}
	return output;
}

void	Sed::writeOutput(std::string filename, std::string str)
{
	std::ofstream	output;

	output.open(filename.c_str());
	if (!output.is_open())
	{
		std::cout << "Unable to open output file" << std::endl;
		this->errorOccured = true;
		return;
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '\\' && i + 1 < str.length() && str[i + 1] == 'n')
		{
			output << '\n';
			i++;
		}
		else
			output << str[i];
	}
	output.close();
}

std::string	Sed::readFile(std::string filename)
{
	std::ifstream	input;
	std::string		whole_file = "";
	std::string		line = "";

	input.open(filename);
	if (!input.is_open())
	{
		std::cout << "Unable to open input file" << std::endl;
		this->errorOccured = true;
		return whole_file;
	}
	while (getline(input, line))
	{
		if (line.empty())
			whole_file.append("\\n");
		else
		{
			whole_file.append(line);
			whole_file.append("\\n");
		}
	}
	input.close();
	return whole_file;
}

bool	Sed::getErrorStatus(void)
{
	return this->errorOccured;
}