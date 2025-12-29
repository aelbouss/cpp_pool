# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal's Default Constructor Called"<< std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type(name)
{
	std::cout << "WrongAnimal's Parameterized Constructor Called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator = (const WrongAnimal& src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	this->type = src.type;
}
std::string	WrongAnimal::getType() const { return (type); }

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Sound" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal's Destructor Called" << std::endl;
}

