# ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include  <iostream>
# include  "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;
    public:
    AMateria();
    AMateria(const AMateria& src);
    AMateria&   operator=(const AMateria& src);
    ~AMateria();
    AMateria(std::string const & type);
    std::string const & getType() const; //Returns the materia type
    AMateria&   operator = (const AMateria& src);
    AMateria(const AMateria& src);
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

# endif