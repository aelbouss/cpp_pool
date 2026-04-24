# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base * generate(void)
{
	int		choice ;
	Base	*data;

	std::srand(std::time(NULL));
	choice = (std::rand() % 3) + 1;
	if (choice == 1)
		data = new A();
	else if (choice == 2)
		data = new B();
	else if (choice == 3)
		data = new C();
	else
		return (NULL);
	return data ;
}

void identify(Base* p)
{
	A	*Aptr = dynamic_cast<A *>(p);
	if (Aptr)
	{
		std::cout << "The type  is A " << std::endl;
		return ;
	}
	B	*Bptr = dynamic_cast<B *>(p);
	if (Bptr)
	{
		std::cout << "The type  is B " << std::endl;
		return ;	
	}
	C	*Cptr = dynamic_cast<C *>(p);
	if (Cptr)
	{
		std::cout << "The type  is C " << std::endl;
		return ;	
	}
	std::cerr << "invalid type" << std::endl;
}

void identify(Base& p)
{
	
	try
	{
		A	&Aref = dynamic_cast<A &>(p);
		(void)Aref;
		std::cout << "The type  is A reference" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		B	&Bref = dynamic_cast<B &>(p);
		(void)Bref;
		std::cout << "The type  is B reference" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		C	&Cref = dynamic_cast<C &>(p);
		(void)Cref;
		std::cout << "The type  is C reference" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	std::cerr << "Invalid type" << std::endl; 
}

Base::~Base(){}