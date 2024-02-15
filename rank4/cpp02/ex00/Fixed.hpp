/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 15:09:03 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/15 17:27:57 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed& src);
		Fixed & operator=(Fixed const& src);
		~Fixed();
		// Copy constructor
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif