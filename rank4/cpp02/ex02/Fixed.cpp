/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 15:09:05 by Julia         #+#    #+#                 */
/*   Updated: 2024/02/15 23:51:44 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
}

// shifts the integer value left by _bits positions to represent the 
// fractional part of the fixed-point number.
Fixed::Fixed(const int value)
{
	this->_value = value << _fractionalBits;
}

//  multiplies the float value by 1 << _bits to shift the fractional part 
// to the integer part and then rounds it to the nearest integer
Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << _fractionalBits));
}

// Destructor
Fixed::~Fixed() {}

// Copy constructor
Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

// Copy assignment operator
Fixed & Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	 return float(this->_value) / float(1 << _fractionalBits);
}

int		Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &n)
{
	stream << n.toFloat();
	return (stream);
}

bool Fixed::operator>(const Fixed &rhs) const { return _value > rhs.getRawBits(); }
bool Fixed::operator<(const Fixed &rhs) const { return _value < rhs.getRawBits(); }
bool Fixed::operator>=(const Fixed &rhs) const { return _value >= rhs.getRawBits(); }
bool Fixed::operator<=(const Fixed &rhs) const { return _value <= rhs.getRawBits(); }
bool Fixed::operator==(const Fixed &rhs) const { return _value == rhs.getRawBits(); }
bool Fixed::operator!=(const Fixed &rhs) const { return _value != rhs.getRawBits(); }

Fixed	Fixed::operator+(const Fixed &rhs) const { return Fixed(this->toFloat() + rhs.toFloat()); }
Fixed	Fixed::operator-(const Fixed &rhs) const { return Fixed(this->toFloat() - rhs.toFloat()); }
Fixed	Fixed::operator*(const Fixed &rhs) const { return Fixed(this->toFloat() * rhs.toFloat()); }
Fixed	Fixed::operator/(const Fixed &rhs) const { return Fixed(this->toFloat() / rhs.toFloat()); }

Fixed & Fixed::min(Fixed &a, Fixed &b) { return (a < b ? a : b); }
Fixed & Fixed::max(Fixed &a, Fixed &b) { return (a > b ? a : b); }

const Fixed&  Fixed::min(const Fixed &a, const Fixed &b) { return (a < b ? a : b); }
const Fixed& Fixed::max(const Fixed &a, const Fixed &b) { return (a > b ? a : b); }

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	++(*this);
	return temp;
}

Fixed & Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	--(*this);
	return temp;
}

Fixed & Fixed::operator--(void)
{
	_value--;
	return *this;
}
