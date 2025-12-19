# ifndef FIXED_HPP
# define FIXED_HPP

// headers section
# include <iostream>

class	Fixed
{
	private:
		int	fixedpoint;
		static const int	fractional;
	public:
		Fixed(); // constructor
		Fixed& operator = ( const Fixed& src); // copy assignment  operator
		Fixed( const Fixed& src); // copy constructor
		~Fixed(); // destructor
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
		
};

# endif