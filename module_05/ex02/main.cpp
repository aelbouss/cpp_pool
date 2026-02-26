# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat b1(5, "Anass");
		ShrubberyCreationForm f1("Home");
		RobotomyRequestForm f2("random_target");
		PresidentialPardonForm f3("bad_person");
		b1.signForm(f1, b1);
		b1.signForm(f2, b1);
		b1.signForm(f3, b1);
		b1.executeForm(f1);
		b1.executeForm(f2);
		b1.executeForm(f3);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr <<  e.what();
	}
		catch(AForm::GradeTooHighException& e)
	{
		std::cerr <<  e.what();
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr <<  e.what();
	}
	catch(...)
	{
		std::cerr << "exception caught : something went wrong" << std::endl;
	}
	return (0);
}