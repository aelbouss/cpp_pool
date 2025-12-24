# ifndef FIXED_HPP
# define FIXED_HPP

// headers section
# include <iostream>
# include <cmath>


class	Fixed
{
	private:
		int	fixedpoint; // raw bits 
		static const int	scaling_factor = 8;
	public:
		Fixed(); // constructor
		Fixed( const int nbr); // converts the int entred  to  fiexd  point
		Fixed( const float nbr); // converts  the  float entred  to fixed  point
		Fixed& operator = ( const Fixed& src); // copy assignment  operator
		Fixed( const Fixed& src ); // copy constructor
		~Fixed(); // destructor
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed	operator + (const Fixed& src) const;
		Fixed	operator * (const Fixed& src) const;
		Fixed	operator - (const Fixed& src) const;
		Fixed	operator / (const Fixed& src) const;
		bool	operator < (const Fixed& src) const;
		bool	operator > (const Fixed& src) const;
		bool	operator >= (const Fixed& src) const;
		bool	operator <= (const Fixed& src) const;
		bool	operator == (const Fixed& src) const;
		bool	operator != (const Fixed& src) const;
		Fixed	operator ++ (int);
		Fixed	operator ++();
		Fixed	operator --(int);
		Fixed	operator --();
		static Fixed&	min(Fixed& first, Fixed& second);
		static const Fixed&	min(const Fixed& first, const Fixed& second);
		static Fixed&	max(Fixed& first, Fixed& second);
		static const Fixed&	max(const Fixed& first, const Fixed& second);

};

std::ostream&	operator <<( std::ostream &os , const Fixed &src) ;

# endif