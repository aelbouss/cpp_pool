# include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*ptr = NULL;
	std::string	&ref = str;

	ptr = &str;
	std::cout << &str << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;

	std::cout << str << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl; 
	return (0);
}