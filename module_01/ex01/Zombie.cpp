# include "Zombie.hpp"


Zombie::Zombie(void){}

Zombie::~Zombie()
{
	std::cout << "the Zombie : " << Name << " is destroyed" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	Name = name; 
}

void    Zombie::announce ( void )
{
	std::cout << Name << " : Brainzzzzzzzzzzzzz" << std::endl;
}