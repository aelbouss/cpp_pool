# ifndef POINT_HPP
# define POINT_HPP

// headers section
# include "Fixed.hpp"

// class section
class	Point
{
	private:
			const Fixed x;
			const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& src);
		Point& operator = (const Point& src);
		Fixed	get_x() const ;
		Fixed	get_y() const;
		~Point();
};

# endif