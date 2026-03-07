# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :name("nobody")
{
	this->grade = 0;
}
Bureaucrat::Bureaucrat(int Grade, std::string Name) :name(Name)
{
	if (Grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (Grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = Grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) :name(src.name)
{
	this->grade = src.grade;
}
Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& src)
{
	if (this == &src)
		return (*this);
	this->grade = src.grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const { return (name); }

int	 Bureaucrat::getGrade(void) const { return (grade); }


void	Bureaucrat::increment(void)
{
	if ((grade - 1) <= 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << PURPLE << "bureaucrat's value incremented" << RESET << std::endl;
	grade -= 1;
}
void	Bureaucrat::decrement(void)
{
	if ((grade + 1) >= 150)
		throw::Bureaucrat::GradeTooLowException();
	std::cout << PURPLE <<"bureaucrat's value decremented" << RESET << std::endl;
	grade += 1;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		if (form.get_form_status())
		{
			std::cout << GREEN <<"bureaucrat " << this->getName() << " signed the form :"<< RESET << std::endl;
			std::cout << form ;
			return ;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

std::ostream&	operator << (std::ostream& os, const Bureaucrat& b)
{
	os << GREEN << b.getName() << " , bureaucrat grade " << b.getGrade() << RESET;
	return os; 
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's Grade Is Too High");
}


const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's Grade Is Too Low") ;
}