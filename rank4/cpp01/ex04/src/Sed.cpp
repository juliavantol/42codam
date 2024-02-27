/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sed.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/25 23:55:26 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/27 13:48:35 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <fstream>
#include <iostream>

Sed::Sed(void)
{
	this->errorOccured = false;
	this->wholeFile = "";
	this->output = "";
}

void	Sed::replaceString(std::string s1, std::string s2, std::string str)
{
	std::string		output = str;
	size_t			found = str.find(s1);

	if (s1.empty())
		return;
	while (found != std::string::npos)
	{
		output.erase(found, s1.length());
		output.insert(found, s2);
		found = output.find(s1, found + s2.length());
	}
	this->output = output;
}

void	Sed::writeOutput(std::string filename)
{
	std::ofstream	output;
	std::string str	= this->output;

	output.open(filename.c_str());
	if (!output.is_open())
	{
		std::cout << "Unable to open output file" << std::endl;
		this->errorOccured = true;
		return;
	}
	Sed::replaceString("\\n", "\n", this->output);
	output << this->output;
	output.close();
}

void	Sed::readFile(std::string filename)
{
	std::ifstream	input;
	std::string		whole_file = "";
	std::string		line = "";

	input.open(filename);
	if (!input.is_open())
	{
		std::cout << "Unable to open input file" << std::endl;
		this->errorOccured = true;
		return;
	}
	while (getline(input, line))
		whole_file += line + "\\n";
	input.close();
	this->wholeFile = whole_file;
}

bool	Sed::getErrorStatus(void)
{
	return this->errorOccured;
}
