# include  "FragTrap.hpp"


int	main(void)
{
	ClapTrap	c1("first guard");
	ClapTrap	c2("Second guard");
	FragTrap    stg("FragTrap powerful guard");

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
	stg.beRepaired(20);
	stg.highFivesGuys();
}