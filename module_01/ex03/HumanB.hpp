#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    private:
        std::string name;
        Weapon  *weapon;
    public:
        void    attack(void);
        void setWeapon(Weapon &wpn);
        HumanB(std::string name);
        ~HumanB();
};  

#endif