#include "sed_for_losers.hpp"

int main(int ac, char **av)
{

    if (ac != 4)
    {
        std::cerr << "< usage >  filename str1 str2" << std::endl;
        return (1);
    }
    if (!check_substr_existance(av[1], av[2]))
    {
        costume_sed(av[1], av[2], av[3]);
    }
    else
        return (1);
    return (0);
}