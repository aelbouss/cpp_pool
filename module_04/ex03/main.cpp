# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "MateriaSource.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include "Character.hpp"
# include "ICharacter.hpp"

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
            std::cout << GREEN <<"\n=== MY TEST ====\n"<< RESET << std::endl;
            MateriaSource *spells_source = new MateriaSource();
            spells_source->learnMateria(new Ice());
            spells_source->learnMateria(new Cure());
             AMateria    *garbage_materias[4];
            Character   *flex  = new Character("Flex");
            Character   *franky = new Character("Franky");
            AMateria    *spells_holder1 = NULL;
            AMateria    *spells_holder2 = NULL;
            spells_holder1 = spells_source->createMateria("ice");
            spells_holder2 = spells_source->createMateria("ice");
            garbage_materias[0] = spells_holder1;
            garbage_materias[1] = spells_holder2;
            flex->equip(spells_holder1);
            franky->equip(spells_holder2);
            spells_holder1 = spells_source->createMateria("cure");
            spells_holder2 = spells_source->createMateria("cure");
            garbage_materias[2] = spells_holder1;
            garbage_materias[3] = spells_holder2;
            flex->equip(spells_holder1);
            franky->equip(spells_holder2); 
            flex->use(0 , *franky);
            franky->use(0, *flex);
            franky->use(1, *flex);
            flex->use(1, *franky);
            spells_holder1 = spells_source->createMateria("rock");
            if (!spells_holder1)
                std::cout << RED << "the Factory Doesn't learned about  this Materia" <<  RESET << std::endl;
            flex->unequip(8);
            flex->unequip(0);
            flex->unequip(1);
            franky->unequip(1);
            franky->unequip(0);
            for(int i = 0 ; i < 4 ; i++)
                delete garbage_materias[i];
            delete franky;
            delete flex;
            delete spells_source;
        }
        return (0);
}