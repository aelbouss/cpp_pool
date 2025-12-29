# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat's Default Constructor Called" << std::endl;
}

WrongCat&	WrongCat::operator = (const WrongCat& src)
{
	if (this == &src)
		return (*this);
	std::cout << "WrongCat's Copy Assignemnt operator Called" << std::endl;
	this->type = src.type;
	return (*this);
}

WrongCat::WrongCat(const WrongCat& src) :WrongAnimal(src)
{
	std::cout << "WrongCat's Copy Constructor Called" << std::endl;
	this->type = src.type;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat's : meows" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat's Destructor Called" << std::endl;
}