# include  "AMateria.hpp"


AMateria::AMateria() {}

AMateria::AMateria(const AMateria& src) { this->type = src.type;}

AMateria&   AMateria::operator= (const AMateria& src)
{
    if (this == &src)
        return (*this);
    this->type = src.type;
    return (*this);
}

std::string const & AMateria:: getType() const { return (type); }

AMateria::~AMateria() {}

void    AMateria::use(ICharacter& target)
{
    (void) target;
}