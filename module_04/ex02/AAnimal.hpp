# ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class	AAnimal
{
	protected :
		std::string type;
	public:
		AAnimal();
		AAnimal(std::string name);
		AAnimal&	operator = (const AAnimal& src);
		AAnimal(const AAnimal& src);
		std::string getType() const;
		virtual	void makeSound() const = 0;
		virtual ~AAnimal();
};

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

# endif