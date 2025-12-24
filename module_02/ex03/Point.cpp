#include "Point.hpp"


Point::Point() {}

Point::Point(const float a, const float b): x(a), y(b){}

Point::Point(const Point& src) : x(src.x), y(src.y) {} // copy constructor ;

Point&	Point::operator = (const Point& src)  // coppy assignment operator
{
	if (this == &src)
		return (*this);
	return (*this);
}

Fixed	Point::get_x() const { return(x); }

Fixed	Point::get_y() const { return (y); }

Point::	~Point(){}