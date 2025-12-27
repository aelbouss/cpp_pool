# include  "ClapTrap.hpp"


int	main(void)
{
	ClapTrap	c1("anass");
	ClapTrap	c2("wins");

	c1.attack("wins");
	c2.takeDammage(3);
	c2.attack("anass");
	c1.takeDammage(10);
	c1.beRepaired(4);
	c2.beRepaired(5);
	return (0);
}