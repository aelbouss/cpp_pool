#include  "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies;

	zombies = zombieHorde(10, "nothing");
	for(int i = 0 ; i < 10 ; i++)
		zombies->announce();
	delete zombies;
	return (0);
}
