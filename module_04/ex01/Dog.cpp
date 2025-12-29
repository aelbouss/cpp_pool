# include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	brain = new Brain();
	std::cout << "Dog's Default Constructor Called" << std::endl;
}


Dog::Dog(const Dog& src) : Animal(src) 
{
	this->brain = src.brain;
	std::cout << "Dog's Copy Constructor Called" << std::endl;
}

Dog&	Dog::operator = (const Dog& src)
{
	if (this == &src)
		return (*this);
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	delete this->brain;
	this->brain = new Brain();
	this->brain = src.brain;
	Animal::operator=(src);
	return (*this);
}

void	Dog::get_dog_ideas()
{
	for(int i = 0 ; i < 100 ; i++)
	{
		std::cout << brain->ideas[i] << std::endl; 
	}
}

void	Dog::makeSound() const
{
	std::cout << "Dog : Barks" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog's Destructor Called" << std::endl;
}