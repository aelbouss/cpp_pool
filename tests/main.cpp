#include <iostream>
#include <string>


class	base_one
{
	public:
		virtual void print() = 0;
};

class	derived : public base_one
{
	public :
		virtual	void	print()
		{
			std::cout  << "hello  im  the  derived" << std::endl;
		}
};

int	main(void)
{
	derived obj;

	obj.print();

	return (0);
}
