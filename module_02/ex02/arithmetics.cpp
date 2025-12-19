# include "Fixed.hpp"

 // here  must  return the real value 

Fixed	Fixed::operator + (const Fixed& src) const
{
	return (this->fixedpoint + src.getRawBits());
}

Fixed	Fixed::operator - (const Fixed& src) const
{
	return (this->fixedpoint - src.getRawBits());
}


Fixed	Fixed::operator * (const Fixed& src) const
{
	float fv;
	float sv;

	fv = this->toFloat();
	sv = src.toFloat();
 	return (fv * sv);
}

Fixed	Fixed::operator / (const Fixed& src) const
{
	return (this->fixedpoint / src.getRawBits());
}