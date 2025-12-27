# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
    private:
        std::string name;
    public:
         DiamondTrap(std::string Name);
         DiamondTrap&   operator = (const DiamondTrap& src);
         DiamondTrap(const DiamondTrap& src);
         void	attack(const std::string& target);
         void   whoAmI();
        ~DiamondTrap();
};


# endif