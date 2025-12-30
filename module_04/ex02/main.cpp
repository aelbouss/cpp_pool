# include "AAnimal.hpp"
# include  "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include "Brain.hpp"


int main()
{
	Dog dog;
	Cat cat;
	// Animal animal; cannot  be  instantiated 
	AAnimal	*animal;
	animal = &dog;
	std::cout  << GREEN <<"this is a :" << animal->getType() << RESET << std::endl;
	animal->makeSound();
	animal = &cat;
	std::cout << RED << "this is a :" << animal->getType() << RESET << std::endl;
	animal->makeSound();
	return 0;
} 