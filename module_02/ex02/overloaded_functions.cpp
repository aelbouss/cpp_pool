#include "Fixed.hpp"

Fixed&	Fixed::min(Fixed& first, Fixed& second)
{
	if (first < second)
		return (first);
	return (second);
}

const Fixed&	Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first < second)
		return (first);
	return (second);
}

Fixed&	Fixed::max(Fixed& first, Fixed& second)
{
	if (first > second)
		return (first);
	return (second);
}

const Fixed&	Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first > second)
		return (first);
	return (second);
}