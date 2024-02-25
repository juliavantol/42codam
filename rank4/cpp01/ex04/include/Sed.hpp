/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sed.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/25 23:55:22 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/26 00:40:11 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
	public:
		bool	errorOccured;
	
		Sed();
		~Sed() {};
		void		writeOutput(std::string filename, std::string str);
		std::string	replaceString(std::string str, std::string s1, std::string s2);
		std::string	readFile(std::string filename);
		bool		getErrorStatus(void);
};

#endif
