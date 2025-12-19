# include "Fixed.hpp"

bool	Fixed::operator < (const Fixed& src) const
{
	return (this->getRawBits() < src.getRawBits());
}

bool	Fixed::operator > (const Fixed& src) const
{
	return (this->getRawBits() > src.getRawBits());
}

bool	Fixed::operator != (const Fixed& src) const
{
	return (this->getRawBits() != src.getRawBits());
}

bool	Fixed::operator == (const Fixed& src) const
{
	return (this->getRawBits() == src.getRawBits());
}

bool	Fixed::operator >= (const Fixed& src) const
{
	return (this->getRawBits() >= src.getRawBits());
}

bool	Fixed::operator <= (const Fixed& src) const
{
	return (this->getRawBits() <= src.getRawBits());
}