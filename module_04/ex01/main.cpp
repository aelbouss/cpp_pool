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
		Cat	*cat1  = new Cat();
		Cat *cat2 = new Cat(*cat1);
		delete cat1;
		cat2->get_cat_ideas();
		delete cat2;
	}


	return 0;
} 