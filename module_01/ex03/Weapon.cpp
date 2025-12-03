#include "Weapon.hpp"

 const std::string&   Weapon::getType(void) { return (type); }

 void    Weapon::setType(std::string type) { type = type; }
 
Weapon::Weapon(std::string type) :type(type){}

Weapon::Weapon() {}
Weapon::~Weapon() {}