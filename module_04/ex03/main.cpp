# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "MateriaSource.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include "Character.hpp"
# include  "ICharacter.hpp"

int main()
{
        {
            IMateriaSource* src = new MateriaSource();
            src->learnMateria(new Ice());
            src->learnMateria(new Cure());
            ICharacter* me = new Character("me");
            AMateria* tmp;
            tmp = src->createMateria("ice");
            me->equip(tmp);
            tmp = src->createMateria("cure");
            me->equip(tmp);
            ICharacter* bob = new Character("bob");
            me->use(0, *bob);
            me->use(1, *bob);
            delete bob;
            delete me;
            delete src;
        }

        {
            std::cout <<"\n=== TEST ====\n" << std::endl;
            MateriaSource *spells_source = new MateriaSource();
            spells_source->learnMateria(new Ice());
            spells_source->learnMateria(new Cure());
            Character   *flex  = new Character("Flex");
            Character   *franky = new Character("Franky");
            AMateria    *spells_holder = NULL;
            spells_holder = spells_source->createMateria("ice");
            flex->equip(spells_holder);
            franky->equip(spells_holder);
            spells_holder = spells_source->createMateria("cure");
            flex->equip(spells_holder);
            franky->equip(spells_holder);

            flex->use(0 , *franky);
            franky->use(1, *franky);
            franky->use(0, *flex);
            flex->use(1, *franky);
            delete franky;
            delete flex;
            delete spells_source;
            spells_holder = NULL;
        }
}

// check  destructor segFAULT