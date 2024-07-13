/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 12:09:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/13 18:02:47 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include "Helpers.hpp"
# include <cctype>
# include <typeinfo>
# include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		
	public:
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter & operator=(const ScalarConverter &other);

		static void convert(const std::string &literal);

};

#endif