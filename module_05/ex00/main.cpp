# include "Bureaucrat.hpp"

int	main(void)
{

	{	
		try
		{
			Bureaucrat	b1(-1, "anass");
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << RED <<"exception caught : " <<  e.what() << RESET << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << RED <<"exception caught : " <<  e.what() << RESET << std::endl;
		}
	}

	{
		try
		{
			Bureaucrat	b1(160, "anass");
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << RED <<"exception caught : " <<  e.what() << RESET << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
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
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << RED <<"exception caught : " <<  e.what() << RESET << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << RED <<"exception caught : " <<  e.what() << RESET << std::endl;
		}

	}
	return (0);
}