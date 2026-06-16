# ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>
# include <cstdlib>


class RPN
{
    private:
        std::stack<int> container;
    public:
        RPN();
        RPN&    operator = (const RPN& src);
        RPN(const RPN& src);
        ~RPN();
        void    push_value(int nb);
        void    pop_value();
        int     get_top();
        size_t  get_container_size();
};

 void   process_input(char *str);

# endif