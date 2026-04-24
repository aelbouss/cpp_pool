# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"


int	main(void)
{
	Base	*data;

	data = generate();
	Base&	bref = *data;

	identify(data);
	std::cout << "***********************************************" << std::endl;
	identify(bref);
	delete(data);
}