# include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal's Default Constructor Called"<< std::endl;
}

AAnimal::AAnimal(std::string name) : type(name)
{
	std::cout << "AAnimal's Parameterized Constructor Called" << std::endl;
}

AAnimal&	AAnimal::operator = (const AAnimal& src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

AAnimal::AAnimal(const AAnimal& src)
{
	this->type = src.type;
}

std::string	AAnimal::getType() const { return (type); }

AAnimal::~AAnimal()
{
	std::cout << "AAnimal's Destructor Called" << std::endl;
}

