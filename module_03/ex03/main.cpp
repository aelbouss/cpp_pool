# include  "DiamondTrap.hpp"


int	main(void)
{
	DiamondTrap d1("Hulk");
	d1.whoAmI();
	d1.attack("Hind");
	d1.takeDammage(10);
	d1.beRepaired(10);
	d1.highFivesGuys();
	d1.guardGate();
}

// need  to  see  the chaining free destructor  (virtual destructor).