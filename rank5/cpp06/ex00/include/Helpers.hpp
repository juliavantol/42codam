/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Helpers.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/11 13:35:45 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/07/13 18:03:06 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_HPP
#define DEFINES_HPP

# include <iostream>

# define GREEN	"\033[32m"
# define BOLD	"\033[1m"
# define RESET	"\033[0m"
# define RED	"\033[31m"

# define LITERAL_ERROR	0
# define LITERAL_CHAR	1
# define LITERAL_INT	2
# define LITERAL_FLOAT	3
# define LITERAL_DOUBLE	4
# define PSEUDO_LITERAL	5

bool isChar(const std::string &literal);
bool isInt(const std::string &literal);
bool isFloat(const std::string &literal);
bool isDouble(const std::string &literal);

#endif