#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z1;

	z1 = new Zombie("FLEX");
	if (!z1)
	{
		std::cerr << "Bad Allocation" << std::endl;
		return (1);
	}
	z1->announce();
	delete z1;
	randomChump("ROGER");
	return (0);
}