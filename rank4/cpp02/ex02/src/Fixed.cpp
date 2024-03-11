/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 15:09:05 by Julia         #+#    #+#                 */
/*   Updated: 2024/03/11 14:01:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	this->_value = 0;
}

// Int constructor
Fixed::Fixed(const int value)
{
	this->_value = value << _fractionalBits;
}

// Float constructor
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

// Assignment operator
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

// Comparison operators
bool Fixed::operator>(const Fixed &other) const { return _value > other.getRawBits(); }
bool Fixed::operator<(const Fixed &other) const { return _value < other.getRawBits(); }
bool Fixed::operator>=(const Fixed &other) const { return _value >= other.getRawBits(); }
bool Fixed::operator<=(const Fixed &other) const { return _value <= other.getRawBits(); }
bool Fixed::operator==(const Fixed &other) const { return _value == other.getRawBits(); }
bool Fixed::operator!=(const Fixed &other) const { return _value != other.getRawBits(); }

// Arithmetic operators 
Fixed	Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

// Min/max operators
// Takes as parameters two references on fixed-point numbers
Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

// Takes as parameters two references on fixed-point numbers
Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

// Takes as parameters two references to constant fixed-point numbers
const Fixed&  Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

// Takes as parameters two references to constant fixed-point numbers
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

// Increment/decrement operators
// Post-increment
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	++(*this);
	return temp;
}

// Pre-increment
Fixed & Fixed::operator++(void)
{
	_value++;
	return *this;
}

// Post-decrement
Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	--(*this);
	return temp;
}

// Pre-decrement
Fixed & Fixed::operator--(void)
{
	_value--;
	return *this;
}

// Overload << operator to enable output of Fixed object to a stream
std::ostream	&operator<<(std::ostream &stream, Fixed const &n)
{
	stream << n.toFloat();
	return (stream);
}
