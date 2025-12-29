# include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog's Default Constructor Called" << std::endl;
}


Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "Dog's Copy Constructor Called" << std::endl;
}

Dog&	Dog::operator = (const Dog& src)
{
	if (this == &src)
		return (*this);
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	Animal::operator=(src);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog : Barks" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog's Destructor Called" << std::endl;
}