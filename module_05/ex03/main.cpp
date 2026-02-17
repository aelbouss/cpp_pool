# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	b1(5, "anass");
		AForm	*form;
		Intern	Factory;

		form = Factory.makeForm("rf", "Home");
		if (!form)
		{
			std::cout << "the inventory doens't make this form" << std::endl;
			throw "Error";
		}
		b1.signForm(*form, b1);
		b1.executeForm(*form);
		delete (form);
	}
	catch(GradeTooHighException& e)
	{
		std::cerr <<  e.what();
	}
	catch(GradeTooLowException& e)
	{
		std::cerr <<  e.what();
	}
	catch(...)
	{
		std::cerr << "exception caught : something went wrong" << std::endl;
	}
	return (0);
}