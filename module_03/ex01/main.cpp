# include  "ScavTrap.hpp"


int	main(void)
{
	ClapTrap	c1("first guard");
	ClapTrap	c2("Second guard");
	ScavTrap    stg("special guard");

	c1.attack("special gard");
	stg.takeDammage(10);
	c2.attack("special gard");
	stg.takeDammage(10);
	stg.attack("first guard");
	c1.takeDammage(10);
	stg.attack("second guard");
	c2.takeDammage(10);
	c1.beRepaired(10);
	c2.beRepaired(10);
	stg.guardGate();
	// ClapTrap * ptr = new ScavTrap("anass");
	// delete ptr;
	return (0);
}