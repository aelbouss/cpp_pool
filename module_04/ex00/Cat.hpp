# ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat&	operator = (const Cat& src);
		Cat(const Cat& src);
		void	makeSound() const ;
		~Cat();
};

# endif