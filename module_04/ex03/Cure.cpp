# include  "Cure.hpp"


Cure::Cure()
{
    this->type = "cure";
}

Cure::Cure(const Cure& src) :AMateria(src)
{
    this->type = src.getType();
}

Cure&   Cure::operator = (const Cure& src)
{
    if (this == &src)
        return (*this);
    this->type = src.getType();
    return (*this);
}

Cure    *Cure::clone() const
{
    Cure    *p = new Cure();
    return (p);
}

void    Cure::use(ICharacter& target)
{
    std::cout<< "* heals "<< target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure() {}