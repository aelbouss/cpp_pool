# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <queue>
# include <cstdlib>
# include <algorithm>


class   PmergeMe
{
    private:
        std::vector<std::pair<int, int> >   pairs;
        std::vector<int>                    winners_list;
        std::vector<int>                    losers_list;
    public:

        void    assign_pair(int n1, int n2);
        void    display_pairs();
        void    split_args(char **av, int ac);
        void    fill_winners(int nb);
        void    fill_losers(int nb);
        void    display_winners_losers(void);
        PmergeMe();
        PmergeMe&   operator = (const PmergeMe& src);
        PmergeMe(const PmergeMe& src);
        ~PmergeMe();
};


bool    is_even(int args_num);


# define  RED "\e[0;31m"
# define  RESET "\e[0m"
# define GREEN "\e[0;32m"
# define YELLOW	"\e[0;33m"

# endif
