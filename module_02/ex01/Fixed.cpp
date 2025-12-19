# include  "Fixed.hpp"




Fixed::Fixed() // default constructor
{
	fixedpoint = 0;
	std::cout << "Default constructor called" << std::endl;  
} 

Fixed::Fixed( const int nbr) // constructor builds int
{
	this->fixedpoint = nbr * pow(2, scaling_factor);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float nbr) // constructor builds float
{
	this->fixedpoint = roundf(nbr * pow(2, scaling_factor));
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator = ( const Fixed& src) // copy assignment  operator
{
	if (this == &src)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedpoint = src.getRawBits();
	return (*this);
}

Fixed::Fixed( const Fixed& src) // copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() // destructor
{
	this->fixedpoint = 0;
	std::cout << "Destructor called" << std::endl;
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