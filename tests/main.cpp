# include <iostream>

class   car
{
    private:
        std::string name;
    public:
        car()
        {
            std::cout << "the constructor called\n" << std::endl;
        }
        ~car()
        {
            std::cout << "the destructor called" << std::endl;
        }

        void    annonce()
}



int main(void)
{

    return (0);
}