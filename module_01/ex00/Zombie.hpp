
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
        void    randomChump( std::string name );
        void    set_name(std::string name);
        Zombie  *newZombie( std::string name );
        ~Zombie();
};

# endif