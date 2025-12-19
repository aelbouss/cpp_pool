# include  "Fixed.hpp"

Fixed::Fixed() // default constructor
{
	fixedpoint = 0;
	  
} 

Fixed::Fixed( const int nbr) // constructor builds int
{
	setRawBits(roundf(nbr * pow(2, scaling_factor)));
}

Fixed::Fixed( const float nbr) // constructor builds float
{
	setRawBits(roundf(nbr * pow(2, scaling_factor)));
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
	return (static_cast <float>(fixedpoint) / pow(2, scaling_factor));
}

int	Fixed::toInt( void ) const
{
	return (fixedpoint / pow(2, scaling_factor));
}

std::ostream&	operator << ( std::ostream& os , const Fixed &src)
{
	std::cout << src.toFloat();
	return (os);
}