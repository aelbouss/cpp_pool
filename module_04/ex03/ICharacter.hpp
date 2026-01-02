# ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include  <iostream>

class AMateria;

class ICharacter
{
    public:

        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria *m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
        virtual ~ICharacter() {}
};

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

# endif