/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 01:31:21 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/14 14:35:20 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::ofstream	output;
	std::ifstream	input;
	std::string		line;
	std::string		copy_line;
	std::string		temp;

	if (argc != 4)
	{
		std::cout << "Invalid input" << std::endl;
		return 0;
	}
	char		*filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	int			s1_len = s1.length();
	// int			s2_len = s2.length();

	input.open(filename);
	if (input.is_open())
	{
		size_t	found;
	
		while (getline(input, line))
		{
			copy_line = line;
			found = line.find(s1);
			while (found != std::string::npos)
			{
				temp = line.substr(found + s1_len, std::string::npos);
				copy_line.erase(found, std::string::npos);
				copy_line.append(s2);
				copy_line.append(temp);
				found = line.find(s1, found + s1_len);
			}
			std::cout << copy_line << std::endl;
		}
		input.close();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
		return 0;
	}
	output.open("output.txt");
	output << filename << std::endl << s1 << std::endl << s2 << std::endl;
	output.close();
	return 0;
}