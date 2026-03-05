# include "Bureaucrat.hpp"

int	main(void)
{

	{	
		try
		{
			Bureaucrat	b1(-1, "anass");
		}
		catch (const std::exception &e)
		{
			std::cerr << "exception caught : " << RED << e.what() << RESET << std::endl;
		}
	}

	{
		try
		{
			Bureaucrat	b1(160, "anass");
		}
		catch (const std::exception &e)
		{
			std::cerr << "exception caught : "<< RED<< e.what() << RESET << std::endl;
		}
	}

	{
		try
		{
			Bureaucrat	b1(120, "anass");
			std::cout << b1 << std::endl;
			b1.increment();
			std::cout << BLUE << "Bureaucrat's new grade is : " << b1.getGrade() << RESET << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "exception caught : "<< RED << e.what() << RESET <<std::endl;
		}
	}
	return (0);
}