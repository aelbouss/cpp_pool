# include "Fixed.hpp"

static const int	fractional = 8;

Fixed::Fixed() // constructor
{ 
	fixedpoint = 0;
	std::cout << "Default constructor called" << std::endl;  
} 

Fixed::Fixed( const Fixed& src) // copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	fixedpoint = src.getRawBits(); 
} 

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed&	Fixed::operator = ( const Fixed& src) // copy assignment  operator 
{
	if (this == &src)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	fixedpoint = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const 
{
	std::cout << "getRawBits member function called" << std::endl; 
	 return (fixedpoint); 
}

void Fixed::setRawBits( int const raw ) { this->fixedpoint = raw ; }