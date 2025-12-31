# include  "AMateria.hpp"


AMateria::AMateria()
{
    std::cout << "AMateria's Default Constructor Called" << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
    this->type = src.type;
    std::cout << "AMateria's copy Constructor Called" << std::endl;
}

AMateria&   AMateria::operator= (const AMateria& src)
{
    if (this == &src)
        return (*this);
    std::cout  << "AMateria's copy Assignment Operator Called" << std::endl;
    this->type = src.type;
    return (*this);
}


std::string const & AMateria:: getType() const
{
     return (type);
}

AMateria::~AMateria()
{
    std::cout << "AMateria's Destructor  Called" << std::endl;
}