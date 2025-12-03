#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon  weapon;
        std::string Name;
    public:
        std::string get_name(void);
        void    set_name(std::string name);
        void    attack(void);
        HumanB(std::string name);
        void    setWeapon(std::string weapon);
        HumanB();
        ~HumanB();
};  
