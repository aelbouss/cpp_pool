# ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include "ArrayException.hpp"

template	<typename T>

class	array
{
	private:
		T	*arr;
		const int size;
	public:
		array() :arr(NULL) ,size(0) {}
		array(const unsigned int nb) :size(nb) { this->arr = new T[nb](); }

		array&	operator = (const array & src)
		{
			if (this == &src)
				return *this;
			delete[] this->arr;
			this->arr = new T[src.size]();
			for (int i = 0 ; i  <  src.size ; i++)
				this->arr[i] = src.arr[i];
			return *this;
		}

		array(const array& src)
		{
			*this = src ;
		}

		~array() { delete[] this->arr; }

		T	&operator [] (int idx)
		{
				if (idx >= this->size || idx <  0)
					throw ArrayException();
			return (this->arr[idx]);
		}

		int get_size() const 
		{
			return this->size ;
		}
};


# endif