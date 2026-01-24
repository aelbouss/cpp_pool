# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int Grade, std::string Name)
{
	if (Grade > 150)
		throw GradeTooLowException(Grade);
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
		return ;
	grade -= 1;
}
void	Bureaucrat::decrement(void)
{
	if ((grade + 1) >= 150)
		return ;
	grade += 1;
}

std::ostream&	operator << (std::ostream& os, const Bureaucrat& b)
{
	os << GREEN << b.name << " , bureaucrat grade " << b.grade << RESET;
	return os; 
}

void	Bureaucrat::signForm(Form& f, Bureaucrat& b)
{
	f.beSigned(b);
	if (f.get_form_status())
	{
		std::cout << "bureaucrat signed form" << std::endl;
		return ;
	}
	else
		std::cout << getName() << " Couldn't Sign " <<f.get_name() << " beacause : ";
	if (grade < f.get_sign_grade())
		throw GradeTooHighException(grade);
	else
		throw GradeTooLowException(grade);
}