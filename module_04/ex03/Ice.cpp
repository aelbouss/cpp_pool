# include  "Ice.hpp"


Ice::Ice()
{
    type = "ice";
}

 Ice::Ice(const Ice& src)
 {
    this->type = src.type;
 }

 Ice& Ice::operator = (const Ice& src)
 {
    if (this == &src)
        return (*this);
    this->type = src.type;
    return (*this);
 }

 Ice *Ice::clone() const
 {
    Ice *p = new Ice();
    return (p);
 }

 void   Ice::use(ICharacter & target)
 {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
 }

 Ice::~Ice() {}