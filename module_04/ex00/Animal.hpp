# ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected :
		std::string type;
	public:
		Animal();
		Animal(std::string name);
		Animal&	operator = (const Animal& src);
		Animal(const Animal& src);
		std::string getType() const;
		virtual	void makeSound() const;
		virtual ~Animal();
};

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

# endif