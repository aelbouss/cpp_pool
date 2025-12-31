# ifndef ICE_HPP
# define ICE_HPP

# include  "ICharacter.hpp"
# include  "AMateria.hpp"

class   Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& src);
        Ice& operator = (const Ice& src);
        Ice *clone() const;
        void    use(ICharacter & target);
        ~Ice();

};

# endif