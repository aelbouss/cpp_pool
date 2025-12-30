# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"
# include "Brain.hpp"


int main()
{

	{
		Animal	*animals[10];
		
		for(int i = 0 ; i < 10 ; i++)
		{
			if (i < 5)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		for(int i = 0 ; i < 10 ; i++)
		{
			delete animals[i];
		}
	}

	{
		std::cout << GREEN <<"===== Deep Copy Test ====="<< RESET << std::endl;
		Dog	*dog1  = new Dog();
		Dog *dog2 = new Dog(*dog1);
		delete dog1;
		dog2->get_dog_ideas();
		delete dog2;
	}


	return 0;
} 