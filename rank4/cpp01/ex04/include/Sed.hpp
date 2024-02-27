/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sed.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/25 23:55:22 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/27 13:38:50 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
	public:
		bool		errorOccured;
		std::string	wholeFile;
		std::string	output;
	
		Sed();
		~Sed() {};

		void	replaceString(std::string s1, std::string s2, std::string str);
		void	writeOutput(std::string filename);
		void	readFile(std::string filename);
		bool	getErrorStatus(void);
};

#endif
