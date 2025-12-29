# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include "Brain.hpp"


int main()
{

	// {
	// 	Animal	*animals[10];
		
	// 	for(int i = 0 ; i < 10 ; i++)
	// 	{
	// 		if (i < 5)
	// 			animals[i] = new Dog();
	// 		else
	// 			animals[i] = new Cat();
	// 	}
	// 	for(int i = 0 ; i < 10 ; i++)
	// 	{
	// 		delete animals[i];
	// 	}
	// }

	// {
		
	// 	std::cout << "===== Deep Copy Test =====" << std::endl;
	// 	Dog	*dog1  = new Dog();
	// 	Dog *dog2 = new Dog(*dog1);
	// 	//delete dog2;
	// 	dog1->get_dog_ideas();
	// 	dog2->get_dog_ideas();
		
	// }

	Dog	*d1 = new Dog();
	Dog	*d2 = new Dog(*d1);

	std::cout << "Here" << std::endl;
	d1->getType();
	d2->getType();

	return 0;
} 