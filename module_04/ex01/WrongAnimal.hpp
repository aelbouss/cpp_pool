# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	protected :
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string name);
		WrongAnimal&	operator = (const WrongAnimal& src);
		WrongAnimal(const WrongAnimal& src);
		std::string getType() const;
		void makeSound() const;
		~WrongAnimal();
};

# endif