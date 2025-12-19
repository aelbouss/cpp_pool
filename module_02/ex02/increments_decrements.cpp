# include "Fixed.hpp"


Fixed	Fixed::operator ++ (int) // postfix increment
{
	Fixed	obj(*this);
	fixedpoint++;
	return (obj);
}

Fixed	Fixed::operator ++() // prefexi incement
{
	fixedpoint++;
	return (*this);
}

Fixed	Fixed::operator --(int) // postfix decrement
{
	fixedpoint--;
	return (*this);
}

Fixed	Fixed::operator --() // prefix  decrement
{
	Fixed	obj(fixedpoint);

	fixedpoint--;
	return (obj);
}