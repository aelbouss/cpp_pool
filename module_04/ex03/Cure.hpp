# ifndef CURE_HPP
# define CURE_HPP

# include  "ICharacter.hpp"
# include  "AMateria.hpp"

class   Cure : public  AMateria
{
    public:
        Cure();
        Cure(const Cure& src);
        Cure& operator = (const Cure& src);
        ~Cure();
        Cure    *clone() const;
        void    use(ICharacter& target);

};

# endif