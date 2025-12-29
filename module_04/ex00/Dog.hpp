# ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog&	operator = (const Dog& src);
		Dog(const Dog& src);
		void	makeSound() const ;
		~Dog();
};

# endif