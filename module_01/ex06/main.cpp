#include  "Harl.hpp"

int main(int ac, char **av)
{
    Harl    comp;
    std::string str;

    if (ac != 2)
    {
        std::cerr << "<usage> : ./ProgramName  Arg" << std::endl;
        return (1);
    }
    str = av[1];
    comp.complain(str);
    return (0);
}