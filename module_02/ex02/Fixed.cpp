# include  "Fixed.hpp"

const int	Fixed::scaling_factor = 8;

Fixed::Fixed() { fixedpoint = 0; } // default constructor

Fixed::Fixed( const int nbr) // constructor builds int
{
	setRawBits((nbr * (1 << scaling_factor)));
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
	this->fixedpoint = src.getRawBits();
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
	return ((float)(this->getRawBits()) / (float)(1 << scaling_factor));
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
	Fixed	res;

	res.setRawBits(this->getRawBits() + src.getRawBits());
	return (res);
}

Fixed	Fixed::operator - (const Fixed& src) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() - src.getRawBits());
	return (res);
}

Fixed	Fixed::operator * (const Fixed& src) const
{
	Fixed	res;

	res.setRawBits((this->getRawBits() * src.getRawBits()) / (1 << scaling_factor));
	return (res);
}

Fixed	Fixed::operator / (const Fixed& src) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() * (1 << scaling_factor) / src.getRawBits());
	return (res);
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
	this->fixedpoint++;
	return (obj);
}

Fixed	Fixed::operator ++() // prefexi incement
{
	this->fixedpoint++;
	return (*this);
}

Fixed	Fixed::operator --(int) // postfix decrement
{
	this->fixedpoint--;
	return (*this);
}

Fixed	Fixed::operator --() // prefix  decrement
{
	Fixed	obj(fixedpoint);

	this->fixedpoint--;
	return (obj);
}

Fixed&	Fixed::min(Fixed& first, Fixed& second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

const Fixed&	Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

Fixed&	Fixed::max(Fixed& first, Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}

const Fixed&	Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}