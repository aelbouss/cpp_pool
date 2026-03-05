# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
{
	this->grade = 0;
	this->name = "nobody";
}

Bureaucrat::Bureaucrat(int Grade, std::string Name)
{
	if (Grade > 150)
		throw Bureaucrat::GradeTooLowException(Grade);
	if (Grade < 1)
		throw GradeTooHighException(Grade);
	this->grade = Grade;
	this->name = Name;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	this->grade = src.grade;
	this->name = src.name;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& src)
{
	if (this == &src)
		return (*this);
	this->grade = src.grade;
	this->name = src.name;
	return (*this);
}

std::string	Bureaucrat::getName(void) const { return (name); }

int	 Bureaucrat::getGrade(void) const { return (grade); }


void	Bureaucrat::increment(void)
{
	if ((grade - 1) <= 1)
		throw Bureaucrat::GradeTooHighException(grade - 1);
	std::cout << PURPLE <<"bureaucrat's value incremented" << RESET << std::endl;
	grade -= 1;
}
void	Bureaucrat::decrement(void)
{
	if ((grade + 1) >= 150)
		throw::Bureaucrat::GradeTooLowException(grade + 1);
	std::cout << PURPLE <<"bureaucrat's value decremented" << RESET << std::endl;
	grade += 1;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		if (form.get_form_status())
		{
			std::cout << GREEN <<"bureaucrat " << this->getName()<< " signed the form :"<< RESET << std::endl;
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

Bureaucrat::GradeTooHighException::GradeTooHighException(int Grade) :grade(Grade){}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's Grade Is Too High");
}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}


Bureaucrat::GradeTooLowException::GradeTooLowException(int Grade) :grade(Grade){}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's Grade Is Too Low") ;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
	form.perform_task();
	std::cout << BLUE << this->name << " executed " << form.get_name() << RESET << std::endl;
}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
