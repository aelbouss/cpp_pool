# include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal's Default Constructor Called"<< std::endl;
}

Animal::Animal(std::string name) : type(name)
{
	std::cout << "Animal's Parameterized Constructor Called" << std::endl;
}

Animal&	Animal::operator = (const Animal& src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

Animal::Animal(const Animal& src)
{
	this->type = src.type;
}
std::string	Animal::getType() const { return (type); }

void	Animal::makeSound() const
{
	std::cout << "Animal Sound" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal's Destructor Called" << std::endl;
}

