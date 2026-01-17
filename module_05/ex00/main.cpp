# include "Bureaucrat.hpp"

int	main(void)
{

	{	
		try
		{
			Bureaucrat	b1(-1, "anass");
		}
		catch(GradeTooHighException& e)
		{
			std::cerr << RED <<"exception caught : " <<  e.what() << RESET << std::endl;
		}
		catch(GradeTooLowException& e)
		{
			std::cerr << RED <<"exception caught : " <<  e.what() << RESET << std::endl;
		}
	}

	{
		try
		{
			Bureaucrat	b1(160, "anass");
		}
		catch(GradeTooHighException& e)
		{
			std::cerr << RED <<"exception caught : " <<  e.what() << RESET << std::endl;
		}
		catch(GradeTooLowException& e)
		{
			std::cerr << RED <<"exception caught : " <<  e.what() << RESET << std::endl;
		}
	}

	{
		try
		{
			Bureaucrat	b1(120, "anass");
			std::cout << b1;
		}
		catch(GradeTooHighException& e)
		{
			std::cerr << RED <<"exception caught : " <<  e.what() << RESET << std::endl;
		}
		catch(GradeTooLowException& e)
		{
			std::cerr << RED <<"exception caught : " <<  e.what() << RESET << std::endl;
		}

	}
	return (0);
}