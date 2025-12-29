# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat&	operator = (const WrongCat& src);
		WrongCat(const WrongCat& src);
		void	makeSound() const ;
		~WrongCat();
};

# endif