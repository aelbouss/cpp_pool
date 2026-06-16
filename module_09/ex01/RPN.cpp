# include "RPN.hpp"

RPN::RPN(){}

RPN&    RPN::operator = (const RPN& src)
{
    if (this != &src)
        this->container = src.container;
    return (*this);
}

RPN::RPN(const RPN& src)
{
    *this = src;
}
RPN::~RPN() {}

size_t  RPN::get_container_size()
{
    return (container.size());
}

void    RPN::push_value(int nb)
{
    container.push(nb);
}

void     RPN::pop_value()
{
    container.pop();
}

int    RPN::get_top()
{
    return (container.top());
}


 void    process_input(char *str)
 {
    std::string input(str);
    int nb1, nb2;
    RPN obj;
    int res = 0;

    if (input.empty())
        throw std::runtime_error("empty input !");
    if (input.find_first_not_of(" \t\r") == std::string::npos)
        throw std::runtime_error("empty input !");

    for (size_t i = 0 ; i < input.size() ; i++)
    {
        if (!(input[i] >= '0' && input[i] <= '9') && input[i] != '*' && input[i] != '+'  &&  input[i] != '-' && input[i] != '/' && input[i] != ' ')
         throw std::runtime_error("Error");
        if (input[i] >= '0' && input[i] <= '9')
        {
            obj.push_value(input[i] - '0');
        }
        else if ((input[i] != ' ') && (obj.get_container_size() == 2))
        {
            nb2 = obj.get_top();
            obj.pop_value();
            nb1 = obj.get_top();
            obj.pop_value();
            if (input[i] == '-')
            {
                res = nb1 - nb2;
                obj.push_value(res);
                 
            }
            else if (input[i] == '+')
            {
                res = nb1 + nb2 ;
                obj.push_value(res);
            }
            else if (input[i] == '*')
            {
                res = nb1 * nb2 ;
                obj.push_value(res);
            }
            else if (input[i] == '/')
            {
                if (nb2 <= 0)
                    throw std::runtime_error("Error : division by zero is impossible");
                 res = nb1 / nb2 ;
                 obj.push_value(res);
            }
        }
    }
        if (obj.get_container_size() == 1)
            std::cout << obj.get_top() << std::endl;
 }