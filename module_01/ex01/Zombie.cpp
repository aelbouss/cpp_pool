# include "Zombie.hpp"


Zombie::Zombie(void){}

Zombie::~Zombie()
{
	std::cout << RED << "the Zombie : " << Name << " is destroyed" << RESET <<std::endl;
}

void	Zombie::set_name(std::string name)
{
	Name = name; 
}

void    Zombie::announce ( void )
{
	std::cout << GREEN << Name << " : Brainzzzzzzzzzzzzz"<< RESET << std::endl;
}