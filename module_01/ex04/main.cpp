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
        std::cout << "the  substr exists" << std::endl;
        copy_content(av[1]);
    }
    else
        std::cout << "the  substr doesnt  exist" << std::endl;
    return (0);
}