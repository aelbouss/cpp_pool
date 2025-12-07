#include  "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies;
	int	zombiesnum;

	zombiesnum = 10;
	zombies = zombieHorde(zombiesnum, "nothing");
	if (!zombies)
	{
		std::cerr << "Bad Allocation" << std::endl;
		return (1);
	}
	for(int i = 0 ; i < zombiesnum; i++)
	{
		std::cout << "[" << i << "] : ";
		zombies[i].announce();
	}
	delete[]  zombies;
	return (0);
}