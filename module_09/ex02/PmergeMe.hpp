# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <queue>
# include <list>
# include <cstdlib>
# include <algorithm>


    struct  Element
    {
        int nbr;
        std::list <Element*> defeated;
    };

    class   PmergeMeList
    {
        private:
                std::list<Element *> container;
        public:
                PmergeMeList();
                PmergeMeList(int , char **av);
                PmergeMeList&   operator << (const PmergeMeList&  src);
                PmergeMeList(const PmergeMeList& src);
                ~PmergeMeList();

                void    Collect_sequence(int ac, char **av);
                void    display_container(void);
                std::list<Element *>    get_container();
                std::list<Element *> recrusive_sort(std::list<Element *>);
    };

    void    colllcet_and_process();
    bool    is_even(int args_num);

    typedef std::list<Element *>::iterator iter

# define  RED "\e[0;31m"
# define  RESET "\e[0m"
# define GREEN "\e[0;32m"
# define YELLOW	"\e[0;33m"

# endif
