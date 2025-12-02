# include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << GREEN << Name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
Zombie::Zombie( std::string name ) : Name(name) {}

Zombie::~Zombie()
{
	std::cout << RED <<"the Zombie " << Name << " is destroyed" << RESET << std::endl;
}