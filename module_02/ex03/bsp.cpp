# include "Point.hpp"

// result = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x)

Fixed	cross_product( Point const a,  Point const b,   Point const ref)
{
	Fixed	result;

	result = (b.get_x() - a.get_x()) * (ref.get_y() - a.get_y()) - 
		(b.get_y() - a.get_y()) * (ref.get_x() - a.get_x());

	return (result);
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	check_ab ;
	Fixed	check_bc ;
	Fixed	check_ca ;
	
	check_ab = cross_product(a, b, c) * cross_product(a, b, point);
	check_bc = cross_product(b, c , a) * cross_product (b, c , point);
	check_ca = cross_product(c, a, b) * cross_product(c, a, point);

	return((check_ab > 0)  && (check_bc > 0) && (check_ca > 0));
}