# include  "Fixed.hpp"

Fixed::Fixed() // default constructor
{
	fixedpoint = 0;
	  
} 

Fixed::Fixed( const int nbr) // constructor builds int
{
	setRawBits(roundf(nbr * (1 << scaling_factor)));
}

Fixed::Fixed( const float nbr) // constructor builds float
{
	setRawBits(roundf(nbr * (1 << scaling_factor)));
}

Fixed& Fixed::operator = ( const Fixed& src) // copy assignment  operator
{
	if (this == &src)
		return (*this);
	this->fixedpoint = src.getRawBits();
	return (*this);
}

Fixed::Fixed( const Fixed& src) // copy constructor
{
	*this = src;
}

Fixed::~Fixed() // destructor
{
	this->fixedpoint = 0;
}

int	Fixed::getRawBits( void ) const
{
	return (fixedpoint);
}

void Fixed::setRawBits( int const raw )
{
	this->fixedpoint = raw;
}

float Fixed::toFloat( void ) const
{
	return (static_cast <float>(fixedpoint) / (1 << scaling_factor));
}

int	Fixed::toInt( void ) const
{
	return (fixedpoint / (1 << scaling_factor));
}

std::ostream&	operator << ( std::ostream& os , const Fixed &src)
{
	os << src.toFloat();
	return (os);
}

Fixed	Fixed::operator + (const Fixed& src) const
{
	return (this->toFloat() + src.toFloat());
}

Fixed	Fixed::operator - (const Fixed& src) const
{
	return (this->toFloat() - src.toFloat());
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