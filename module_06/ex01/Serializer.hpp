# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

class	Data;

class	Serializer
{
	private:
		Serializer();
		Serializer&	operator = (const Serializer& o);
		Serializer(const Serializer& o);
		~Serializer();
	public :
	static uintptr_t	serialize(Data *ptr);
	static	Data	*deserialize(uintptr_t raw);
};

# endif