#include  "Harl.hpp"

int main(void)
{
    Harl    comp;

    comp.complain("DEBUG");
    comp.complain("ERROR");
    comp.complain("INFO");
    comp.complain("ERROR");
    comp.complain("NOTHING");
    comp.complain("");
    return (0);
}