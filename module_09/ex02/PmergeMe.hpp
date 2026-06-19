# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <queue>
# include <list>
# include <cstdlib>
# include <algorithm>


    class   PmergeMeList
    {
        private:
                struct  Element
                {
                    int nbr;
                    std::list <Element*> defeated;
                };
               // std::list<Elements *> container;
                std::list<int>  container;
        public:
                PmergeMeList();
                PmergeMeList&   operator << (const PmergeMeList&  src);
                PmergeMeList(const PmergeMeList& src);
                ~PmergeMeList();

                void    Collect_sequence(int ac, char **av);

                std::list<Element *>    rec_sort(std::list<Element *>);
    };


bool    is_even(int args_num);


# define  RED "\e[0;31m"
# define  RESET "\e[0m"
# define GREEN "\e[0;32m"
# define YELLOW	"\e[0;33m"

# endif
