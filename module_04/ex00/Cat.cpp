# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat's Default Constructor Called" << std::endl;
}

Cat&	Cat::operator = (const Cat& src)
{
	if (this == &src)
		return (*this);
	std::cout << "Cat's Copy Assignemnt operator Called" << std::endl;
	this->type = src.type;
	return (*this);
}

Cat::Cat(const Cat& src) :Animal(src)
{
	std::cout << "Cat's Copy Constructor Called" << std::endl;
	this->type = src.type;
}

void	Cat::makeSound() const
{
	std::cout << "Cat's : meows" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat's Destructor Called" << std::endl;
}
