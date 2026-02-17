# include "Intern.hpp"

Intern::Intern()
{

}
Intern&	Intern::operator = (const Intern& src)
{
	if (this == &src)
		return (*this);
	return (*this);
}
		
Intern::Intern(Intern& src)
{
	*this = src;
}


AForm	*make_ShrubberyCreationForm(std::string target)
{
	AForm	*obj = new ShrubberyCreationForm(target);
	if (!obj)
	{
		std::cout << "Bad Allocation" << std::endl;
		throw "Bad Allocation";
	}
	return (obj);
}

AForm	*make_RobotomyRequestForm(std::string target)
{
	AForm	*obj = new RobotomyRequestForm(target);
	if (!obj)
	{
		std::cout << "Bad Allocation" << std::endl;
		throw "Bad Allocation";
	}
	return (obj);
}

AForm	*make_PresidentialPardonForm(std::string target)
{
	AForm	*obj = new PresidentialPardonForm(target);
	if (!obj)
	{
		std::cout << "Bad Allocation" << std::endl;
		throw "Bad Allocation";
	}
	return (obj);
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm	*(*funcptr[3])(std::string) = 
	{
		&make_ShrubberyCreationForm,
		&make_RobotomyRequestForm,
		&make_PresidentialPardonForm
	};
	for(int i = 0 ; i < 3 ; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates :  " << forms[i] << std::endl;
			return (funcptr[i](target));
		}
	}
	return (NULL);
}

Intern::~Intern()
{
}

