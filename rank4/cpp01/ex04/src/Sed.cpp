/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sed.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/25 23:55:26 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/27 22:44:46 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <fstream>
#include <iostream>

Sed::Sed(void)
{
	this->_errorOccured = false;
	this->_wholeFile = "";
	this->_output = "";
	this->_s1 = "";
	this->_s2 = "";
}

std::string	Sed::replaceString(std::string s1, std::string s2, std::string str)
{
	std::string		output = str;
	size_t			found = str.find(s1);

	while (found != std::string::npos)
	{
		output.erase(found, s1.length());
		output.insert(found, s2);
		found = output.find(s1, found + s2.length());
	}
	this->_output = output;
	return output;
}

void	Sed::writeOutput(std::string filename)
{
	std::ofstream	output;

	output.open(filename.c_str());
	if (!output.is_open())
	{
		std::cout << "Unable to open output file" << std::endl;
		this->_errorOccured = true;
		return;
	}
	Sed::replaceString("\\n", "\n", this->_output);
	output << this->_output;
	output.close();
}

void	Sed::parseInput(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	input;
	std::string		whole_file = "";
	std::string		line = "";

	this->_s1 = Sed::replaceString("\n", "\\n", s1);
	this->_s2 = Sed::replaceString("\n", "\\n", s2);
	input.open(filename);
	if (!input.is_open())
	{
		std::cout << "Unable to open input file" << std::endl;
		this->_errorOccured = true;
		return;
	}
	while (getline(input, line))
		whole_file += line + "\\n";
	input.close();
	this->_wholeFile = whole_file;
}

bool	Sed::getErrorStatus(void)
{
	return this->_errorOccured;
}

std::string	Sed::getStr1(void)
{
	return this->_s1;
}

std::string	Sed::getStr2(void)
{
	return this->_s2;
}

std::string	Sed::getWholeFile(void)
{
	return this->_wholeFile;
}
