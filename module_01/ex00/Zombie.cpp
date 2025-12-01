# include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << Name << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie	*Zombie::newZombie( std::string name )
{
	Zombie	*z = new Zombie(name);
	if (!z)
		return (NULL);
	return (z);
}

void	Zombie::randomChump( std::string name );
{
	Zmobie	z;

	z.set_name(name);
	z.announce();
	z.~Zmobie();
}

/*Zombie::Zombie(string::name)  Name(name) {}

~Zombie::Zombie()
{
	std::cout << "the Zombie "<< name <<"destroyed" std::endl;
}*/