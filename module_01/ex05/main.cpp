#include  "Harl.hpp"

int main(void)
{
    Harl    comp;

    comp.complain("DEBUG");
    comp.complain("ERROR");
    comp.complain("INFOS");
    comp.complain("WARNING");
    comp.complain("NOTHING");
    comp.complain("");
    return (0);
}