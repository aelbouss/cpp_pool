# ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

AForm	*make_ShrubberyCreationForm(std::string target);
AForm	*make_RobotomyRequestForm(std::string target);
AForm	*make_PresidentialPardonForm(std::string target);

class Intern
{
	public:
		Intern();
		~Intern();
		Intern&	operator = (const Intern& src);
		Intern(Intern& src);
		AForm	*makeForm(std::string formName, std::string target);
};

# endif