
# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

// headers section 
# include <iostream>
# include <string>

// classes section

class   Zombie
{
    private:
        std::string Name;
    public:
        Zombie( std::string );
        void    announce ( void );
        ~Zombie();
};

    void	randomChump( std::string name );
    Zombie  *newZombie( std::string name );

    # define GREEN "\033[0;32m"
    # define RED   "\033[0;31m"
    # define RESET "\033[0m"

# endif