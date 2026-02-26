# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat b1(14 , "anass");
			Form f1("F1-FF", 10 , 12);
			b1.increment();
			b1.signForm(f1, b1);
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr <<  e.what();
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr <<  e.what();
		}
			catch(Form::GradeTooHighException& e)
		{
			std::cerr <<  e.what();
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr <<  e.what();
		}

	}
	std::cout << "\n";
	{
		try
		{
			Bureaucrat b1(14, "anass");
			Form f1("F1-FF", 10 , 12);
			b1.signForm(f1, b1);
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr <<  e.what();
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cerr <<  e.what();
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr <<  e.what();
		}
	}
	
	return (0);
}