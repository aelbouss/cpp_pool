# include "ArrayException.hpp"


const char	*ArrayException::what() const throw()
{
	return "Error : out of bounds value";
}