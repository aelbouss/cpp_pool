# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat b1(11 , "anass");
			Form f1("F1-FF", 10 , 12);
			b1.signForm(f1, b1);
		}
		catch(GradeTooHighException& e)
		{
			std::cerr <<  e.what();
		}
		catch(GradeTooLowException& e)
		{
			std::cerr <<  e.what();
		}
	
	}
	std::cout << "\n";
	{
		try
		{
			Bureaucrat b1(8 , "anass");
			Form f1("F1-FF", 10 , 12);
			b1.increment();
			b1.signForm(f1, b1);
		}
		catch(GradeTooHighException& e)
		{
			std::cerr <<  e.what();
		}
		catch(GradeTooLowException& e)
		{
			std::cerr <<  e.what();
		}
	}
	
	return (0);
}