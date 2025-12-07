#include  "HumanB.hpp"
#include  "Weapon.hpp"

void    HumanB::attack(void)
{
    if (!weapon)
    {
        std::cerr << name << " : doesnt have weapon !" << std::endl;
        return ;
    }
    std::cout << name << " : attacks with their : " << weapon->getType() << std::endl; 
}
void    HumanB::setWeapon(Weapon &wpn)
{
     weapon = &wpn;
}
HumanB::HumanB(std::string name) : name(name), weapon(NULL){}

HumanB::~HumanB() {}