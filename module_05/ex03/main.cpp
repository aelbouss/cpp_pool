# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int	main(void)
{
	std::srand(time(0));
	try
	{
		Bureaucrat	b1(5, "anass");
		AForm	*form;
		Intern	Factory;

		form = Factory.makeForm("Rob", "Home");
		if (!form)
		{
			std::cout << "the inventory doens't make this form" << std::endl;
			throw "Error : invalid Form";
		}
		b1.signForm(*form);
		b1.executeForm(*form);
		delete (form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "exception caught : " << RED << e.what() << RESET << std::endl;
	}
	catch (const char * err)
	{
		std::cerr << "exception caught : " << RED << err << RESET << std::endl; 
	}
	return (0);
}