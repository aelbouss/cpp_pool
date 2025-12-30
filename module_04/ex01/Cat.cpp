# include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	brain = new Brain();
	for(int i = 0 ; i <  100 ; i++)
	{
		this->brain->ideas[i] = "Cat Ideas";
	}
	std::cout << "Cat's Default Constructor Called" << std::endl;
}

Cat&	Cat::operator = (const Cat& src) 
{
	if (this == &src)
		return (*this);
	std::cout << "Cat's Copy Assignemnt operator Called" << std::endl;
	this->type = src.getType();
	delete this->brain;
	this->brain = new Brain();
	*(this->brain) = *(src.brain);
	return (*this);
}

Cat::Cat(const Cat& src) :Animal(src)
{
	this->brain = new Brain();
	*this->brain = *(src.brain);
	std::cout << "Cat's Copy Constructor Called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat's : meows" << std::endl;
}

void	Cat::get_cat_ideas()
{
	for(int i = 0 ; i < 100 ; i++)
	{
		std::cout << this->brain->ideas[i] << std::endl;
	}
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat's Destructor Called" << std::endl;
}
