# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"


int main()
{
	{
		std::cout << GREEN << "===== Right Test =====\n\n"<< RESET << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta; 
		delete j;
		delete i;
	}

	{
		std::cout << "\n\n";
		std::cout << RED <<"===== Wrong Test =====\n\n"<< RESET << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output just the wong animal sound sound!
		meta->makeSound();
		delete meta;
		delete i;
	}

	return 0;
}