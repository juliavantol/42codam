/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sed.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/25 23:55:22 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/27 22:44:28 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
	private:
		bool		_errorOccured;
		std::string	_wholeFile;
		std::string	_s1;
		std::string	_s2;
		std::string	_output;
		
	public:
		Sed();
		~Sed() {};

		std::string	replaceString(std::string s1, std::string s2, std::string str);
		std::string	getStr1(void);
		std::string	getStr2(void);
		std::string	getWholeFile(void);

		void		writeOutput(std::string filename);
		void		parseInput(std::string filename, std::string s1, std::string s2);
		bool		getErrorStatus(void);
};

#endif
